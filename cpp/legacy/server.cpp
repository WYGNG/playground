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

//构建需要发送的报文数据buffer
void fill_buf(char* buf, uint8_t filename_len, char* filename, char* data, int i, int length) {
	buf[0] = 0xB0;
	//GID
	buf[1] = 0x01;
	buf[2] = 0x01;
	buf[3] = 0x01;
	buf[4] = 0x01;
	buf[5] = 0x01;
	buf[6] = 0x01;
	//0xde
	buf[7] = 0xde;
	//文件名长度
	buf[8] = filename_len;
	//文件名
	memcpy(buf + 9, filename, filename_len);
	//id个数
	buf[filename_len + 9] = 1;
	//分片数(序号)
	char frag[2];
	frag[0] = i >> 8;
	frag[1] = i;
	memcpy(buf + 10 + filename_len, frag, 2);
	//总分片数
	int frag_size = (length - 1) / 1400 + 1;
	frag[0] = frag_size >> 8;
	frag[1] = frag_size;
	memcpy(buf + 12 + filename_len, frag, 2);
	//分片报文长度
	char len[2];
	//判定是否是最后一个分片
	if (i == (length - 1) / 1400)//为最后一个分片
	{

		len[0] = ((length - i * 1400) >> 8) & 0xff;
		len[1] = (length - i * 1400) & 0xff;
	}
	else
	{
		len[0] = (1400 >> 8) & 0xff;
		len[1] = 1400 & 0xff;
	}
	memcpy(buf + 14 + filename_len, len, 2);
	//负载
	//判定是否是最后一个分片
	if (i == (length - 1) / 1400)//为最后一个分片
	{
		memcpy(buf + 16 + filename_len, data + i * 1400, length - i * 1400);
	}
	else
	{
		memcpy(buf + 16 + filename_len, data + i * 1400, 1400);
	}
}

int main() {
	uint8_t filename_len;
	char filename[50] = { 0 };
	printf("Input the filename:");
	scanf("%s", filename);
	filename_len = strlen(filename);

	//初始化udp套接字并绑定到IP和端口号
	int ser_fd;
	ser_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (ser_fd < 0)
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
	if (bind(ser_fd, (struct sockaddr*)&ser_addr, sizeof(ser_addr)))
	{
		printf("Bind ser_fd failure!\n");
		return -1;
	}
	//打开需要发送的文件
	FILE *fp;
	if ((fp = fopen(filename, "rb+")) == NULL) {
		printf("The file can not open!\n");
		return -1;
	}
	//获得文件总长度方便读取
	char* data;
	fseek(fp, 0, SEEK_END);
	int length; //文件总字节数
	length = ftell(fp);
	data = (char *)malloc((length) * sizeof(char));
	rewind(fp);
	//一次性将所有数据读取到data数组中
	if (fread(data, sizeof(char), length, fp) == 0) {
		printf("Can not read the zip file!\n");
		return -1;
	}
	int frag_size = (length - 1) / 1400 + 1; //总分片数
	printf("字节数为%d\n", length);
	printf("总分片数为%d\n", frag_size);
	bool* flag; //用来标志每个分片是否收到ack
	flag = (bool *)malloc((frag_size) * sizeof(char));
	memset(flag, 0, sizeof(flag));
	//下发报文
	for (int i = 0; i < frag_size; i++) {
		char buf[1450] = { 0 };
		fill_buf(buf, filename_len, filename, data, i, length);
		//判定是否是最后一个分片
		if (i == frag_size - 1) { //为最后一个分片
			int last_size = length - i * 1400;//最后一个分片中文件的字节数
			sendto(ser_fd, buf, 16 + filename_len + last_size, 0, (struct sockaddr*)&cli_addr, sizeof(cli_addr));
		}
		else {
			sendto(ser_fd, buf, 1416 + filename_len, 0, (struct sockaddr*)&cli_addr, sizeof(cli_addr));
		}
		sleep(0.5);
	}
	//收取ack报文
	while (1) {
		char rev[100] = { 0 };
		int len = sizeof(ser_addr);
		//接收来自client的ack
		recvfrom(ser_fd, rev, 100, 0, (struct sockaddr*)&ser_addr, (socklen_t *)&len);
		//检查序列号
		int frag_seq = (uint8_t)rev[10 + filename_len] * 256 + (uint8_t)rev[11 + filename_len];
		flag[frag_seq] = 1;
		if (frag_seq + 1 == frag_size) { //最后一个分片
			break;
		}
	}
	for (int i = 0; i < frag_size; i++) {
		if (flag[i] == 0) {
			printf("有分片没有收到！\n");
			return 0;
		}
	}
	printf("全部收到！\n");
}