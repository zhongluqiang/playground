#include <stdio.h>
#include <ctype.h> // isprint()

#define DUMP_HEX(c) printf("%02x ", (c))
#define DUMP_DEC(c) printf("%03d ", (c))
#define DUMP_OCT(c) printf("%04o ", (c))
#define DUMP_BIN(c) printf("%d%d%d%d%d%d%d%d ", ((c)&0x80) >> 7, ((c)&0x40) >> 6, ((c)&0x20) >> 5, ((c)&0x10) >> 4, ((c)&0x8) >> 3, ((c)&0x4) >> 2, ((c)&0x2) >> 1, (c)&0x1)

static inline void dumpchar(unsigned char c, int format) {
	switch (format)	{
		case  2: DUMP_BIN(c); break;
		case  8: DUMP_OCT(c); break;
		case 10: DUMP_DEC(c); break;
		case 16: DUMP_HEX(c); break;
		default: DUMP_HEX(c); break;
	}
}

static inline void dumpdummy(int format) {
	switch (format)	{
		case  2: printf("         "); break;
		case  8: printf("     "); break;
		case 10: printf("    "); break;
		case 16: printf("   "); break;
		default: printf("   "); break;
	}
}

void memdump(const void *addr, unsigned int size, int format) {
	unsigned int i, j, k;
	int step;
	const unsigned char *p = addr;

	/* 只支持二进制、八进制、十进制、十六进制格式显示 */
	if (format != 2 && format != 8 && format != 10 && format != 16) {
		format = 16;
	}
	/* 二进制每行只输出8个字节，其他进制每行输出16字节 */
	step = (format == 2 ? 8 : 16);

	i = 0;
	while(i < size) {
		j = (size - i) > step ? step : (size - i);
		/* 输出当前内存起始地址 */
		printf("%08x: ", i);
		/* 输出原始字节 */
		for(k = 0; k < j; k++) {
			dumpchar(p[i+k], format);
		}
		/* 不足一行补齐空格 */
		while(k++ < step) {
			dumpdummy(format);
		}
		/* 输出可见字符形式 */
		printf(" |");
		for(k = 0; k < j; k++) {
			printf("%c", isprint(p[i+k]) ? p[i+k] : '.');
		}
		/* 不足一行补齐空格 */
		while(k++ < step) {
			printf(" ");
		}
		printf("|\n");
		i += j;
	}
	printf("[END]\n");
}
