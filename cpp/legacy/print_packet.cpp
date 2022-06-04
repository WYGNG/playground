#include "stdio.h"
#include "stdlib.h"

//print functions
void print_packet(char * buf, int len) {
	int i;
	printf("packet len: %3d\n", len);
	for (i = 0; (len - i) / 10; i += 10) {
		printf("%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n", buf[i], buf[i + 1], buf[i + 2], buf[i + 3], buf[i + 4], buf[i + 5], buf[i + 6], buf[i + 7], buf[i + 8], buf[i + 9]);
	}
	switch (len - i)
	{
	case 9: printf("%02x %02x %02x %02x %02x %02x %02x %02x %02x\n", buf[i], buf[i + 1], buf[i + 2], buf[i + 3], buf[i + 4], buf[i + 5], buf[i + 6], buf[i + 7], buf[i + 8]); break;
	case 8: printf("%02x %02x %02x %02x %02x %02x %02x %02x\n", buf[i], buf[i + 1], buf[i + 2], buf[i + 3], buf[i + 4], buf[i + 5], buf[i + 6], buf[i + 7]); break;
	case 7: printf("%02x %02x %02x %02x %02x %02x %02x\n", buf[i], buf[i + 1], buf[i + 2], buf[i + 3], buf[i + 4], buf[i + 5], buf[i + 6]); break;
	case 6: printf("%02x %02x %02x %02x %02x %02x\n", buf[i], buf[i + 1], buf[i + 2], buf[i + 3], buf[i + 4], buf[i + 5]); break;
	case 5: printf("%02x %02x %02x %02x %02x\n", buf[i], buf[i + 1], buf[i + 2], buf[i + 3], buf[i + 4]); break;
	case 4: printf("%02x %02x %02x %02x\n", buf[i], buf[i + 1], buf[i + 2], buf[i + 3]); break;
	case 3: printf("%02x %02x %02x\n", buf[i], buf[i + 1], buf[i + 2]); break;
	case 2: printf("%02x %02x\n", buf[i], buf[i + 1]); break;
	case 1: printf("%02x\n", buf[i]); break;
	}
}

int main() {
	char buf[] = { 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55 };
	print_packet(buf, sizeof(buf));

	system("pause");
	return 0;
}