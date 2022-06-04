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

//������Ҫ���͵ı�������buffer
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
	//�ļ�������
	buf[8] = filename_len;
	//�ļ���
	memcpy(buf + 9, filename, filename_len);
	//id����
	buf[filename_len + 9] = 1;
	//��Ƭ��(���)
	char frag[2];
	frag[0] = i >> 8;
	frag[1] = i;
	memcpy(buf + 10 + filename_len, frag, 2);
	//�ܷ�Ƭ��
	int frag_size = (length - 1) / 1400 + 1;
	frag[0] = frag_size >> 8;
	frag[1] = frag_size;
	memcpy(buf + 12 + filename_len, frag, 2);
	//��Ƭ���ĳ���
	char len[2];
	//�ж��Ƿ������һ����Ƭ
	if (i == (length - 1) / 1400)//Ϊ���һ����Ƭ
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
	//����
	//�ж��Ƿ������һ����Ƭ
	if (i == (length - 1) / 1400)//Ϊ���һ����Ƭ
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

	//��ʼ��udp�׽��ֲ��󶨵�IP�Ͷ˿ں�
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
	//����Ҫ���͵��ļ�
	FILE *fp;
	if ((fp = fopen(filename, "rb+")) == NULL) {
		printf("The file can not open!\n");
		return -1;
	}
	//����ļ��ܳ��ȷ����ȡ
	char* data;
	fseek(fp, 0, SEEK_END);
	int length; //�ļ����ֽ���
	length = ftell(fp);
	data = (char *)malloc((length) * sizeof(char));
	rewind(fp);
	//һ���Խ��������ݶ�ȡ��data������
	if (fread(data, sizeof(char), length, fp) == 0) {
		printf("Can not read the zip file!\n");
		return -1;
	}
	int frag_size = (length - 1) / 1400 + 1; //�ܷ�Ƭ��
	printf("�ֽ���Ϊ%d\n", length);
	printf("�ܷ�Ƭ��Ϊ%d\n", frag_size);
	bool* flag; //������־ÿ����Ƭ�Ƿ��յ�ack
	flag = (bool *)malloc((frag_size) * sizeof(char));
	memset(flag, 0, sizeof(flag));
	//�·�����
	for (int i = 0; i < frag_size; i++) {
		char buf[1450] = { 0 };
		fill_buf(buf, filename_len, filename, data, i, length);
		//�ж��Ƿ������һ����Ƭ
		if (i == frag_size - 1) { //Ϊ���һ����Ƭ
			int last_size = length - i * 1400;//���һ����Ƭ���ļ����ֽ���
			sendto(ser_fd, buf, 16 + filename_len + last_size, 0, (struct sockaddr*)&cli_addr, sizeof(cli_addr));
		}
		else {
			sendto(ser_fd, buf, 1416 + filename_len, 0, (struct sockaddr*)&cli_addr, sizeof(cli_addr));
		}
		sleep(0.5);
	}
	//��ȡack����
	while (1) {
		char rev[100] = { 0 };
		int len = sizeof(ser_addr);
		//��������client��ack
		recvfrom(ser_fd, rev, 100, 0, (struct sockaddr*)&ser_addr, (socklen_t *)&len);
		//������к�
		int frag_seq = (uint8_t)rev[10 + filename_len] * 256 + (uint8_t)rev[11 + filename_len];
		flag[frag_seq] = 1;
		if (frag_seq + 1 == frag_size) { //���һ����Ƭ
			break;
		}
	}
	for (int i = 0; i < frag_size; i++) {
		if (flag[i] == 0) {
			printf("�з�Ƭû���յ���\n");
			return 0;
		}
	}
	printf("ȫ���յ���\n");
}