#include "stdio.h"


int main() {

	unsigned int div = 1 << 25;
	unsigned int gt = 32000000;

	unsigned int output = 590 * div / gt;

	printf("xian cheng hou chu %d\r\n", output);

	output = (590 / gt) * div;

	printf("xian chu hou cheng %d\r\n", output);
	
	//等一下 32 = 2^5  原始 = freq*2^20/10^6;

	output = (590 << 20) / 1000000;
	printf("you hua suan fa %d\n", output);

	unsigned long long output_long = (590 * (unsigned long long)div) / (unsigned long long)gt;

	printf("zhen que da an %llu\r\n", output_long);

	getchar();

	return 0;
}