#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>    // for socket
#include <sys/socket.h>    // for socket
#include <sys/time.h>
#include <unistd.h>
#include <linux/if_ether.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <malloc.h>
#include <hiredis/hiredis.h>
#include <iostream>

using namespace std;

redisContext* c = redisConnect("127.0.0.1", 6379);


void send_ack(int filename_len, char * filename, int frag_seq, int frag_size, int cli_fd, struct sockaddr_in &ser_addr) {
	char * ack_buf;
	ack_buf = (char *)malloc((15 + filename_len) * sizeof(char)); //回复ack的长度
	//0x70
	ack_buf[0] = 0x70;
	//GID
	ack_buf[1] = 0x01;
	ack_buf[2] = 0x01;
	ack_buf[3] = 0x01;
	ack_buf[4] = 0x01;
	ack_buf[5] = 0x01;
	ack_buf[6] = 0x01;
	//0x05
	ack_buf[7] = 0x05;
	//0xde
	ack_buf[8] = 0xde;
	//文件名长
	ack_buf[9] = filename_len;
	//文件名
	memcpy(ack_buf + 10, filename, filename_len);
	//分片数(序号)
	char frag[2];
	frag[0] = frag_seq >> 8;
	frag[1] = frag_seq;
	memcpy(ack_buf + 10 + filename_len, frag, 2);
	//总片数
	frag[0] = frag_size >> 8;
	frag[1] = frag_size;
	memcpy(ack_buf + 12 + filename_len, frag, 2);
	//ack位
	ack_buf[14 + filename_len] = 0xaa;
	sendto(cli_fd, ack_buf, 15 + filename_len, 0, (struct sockaddr*)&ser_addr, sizeof(ser_addr));
}

int main() {
	int cli_fd;
	char data[500000];//存放数据
	int filename_len;
	char *filename;
	int frag_seq;
	int frag_size;
	int last_len;//存储最后一个分片中文件的长度
	int length; //存储文件总长度
	cli_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (cli_fd < 0)
	{
		printf("create socket fail!\n");
		return -1;
	}
	struct sockaddr_in ser_addr, cli_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ser_addr.sin_port = htons(3000);
	cli_addr.sin_family = AF_INET;
	cli_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	cli_addr.sin_port = htons(3001);
	if (bind(cli_fd, (struct sockaddr*)&cli_addr, sizeof(cli_addr)))
	{
		printf("Bind cli_fd failure!\n");
		return -1;
	}
	while (1) {
		char rev[1500] = { 0 };
		char redis_value[1400] = { 0 };
		int len = sizeof(cli_addr);
		redisReply* reply;
		recvfrom(cli_fd, rev, 1500, 0, (struct sockaddr*)&cli_addr, (socklen_t *)&len);  //接收来自server的信息
		filename_len = (uint8_t)rev[8];//文件名长度
		filename = (char *)malloc((filename_len) * sizeof(char)); //文件名
		memcpy(filename, rev + 9, filename_len);
		frag_seq = (uint8_t)rev[10 + filename_len] * 256 + (uint8_t)rev[11 + filename_len];
		frag_size = (uint8_t)rev[12 + filename_len] * 256 + (uint8_t)rev[13 + filename_len];
		//判定是否是最后一个分片
		if (frag_seq + 1 == frag_size)//为最后一个分片
		{
			last_len = (uint8_t)rev[filename_len + 14] * 256 + (uint8_t)rev[filename_len + 15];//最后一个分片中文件长度
			printf("最后一个分片中文件大小为%d字节\n", last_len);


			memcpy(redis_value, rev + 16 + filename_len, last_len);
			redisCommand(c, "set %d %s", frag_seq, redis_value);
			cout << "frag_seq:" << frag_seq << "saved to redis db" << endl;

			reply = (redisReply*)redisCommand(c, "get %d", frag_seq);
			memcpy(data + frag_seq * 1400, reply->str, last_len);
			length = frag_seq * 1400 + last_len;
			printf("文件总长为%d\n", length);
			send_ack(filename_len, filename, frag_seq, frag_size, cli_fd, ser_addr);
			break;
		}
		else
		{
			memcpy(redis_value, rev + 16 + filename_len, 1400);
			redisCommand(c, "set %d %s", frag_seq, redis_value);
			cout << "frag_seq: " << frag_seq << "   saved to redis db" << endl;

			reply = (redisReply*)redisCommand(c, "get %d", frag_seq);
			memcpy(data + frag_seq * 1400, reply->str, 1400);
		}
		send_ack(filename_len, filename, frag_seq, frag_size, cli_fd, ser_addr);
		sleep(0.5);
	}
	//将接收到的文件写入本地
	FILE *fp;
	if ((fp = fopen("rev.zip", "wb+")) == NULL) {
		printf("The file can not open!\n");
		return -1;
	}
	fwrite(data, length, 1, fp);
	fclose(fp);
}