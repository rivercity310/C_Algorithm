#include <stdio.h>

int sum(int x, int y) {
	return x + y;
}

int mul(int x, int y) {
	return x * y;
}

void kuku(int(*calc)(int, int)) {
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++)
			printf("%3d", (*calc)(i, j));
		putchar('\n');
	}
}

void fpointer() {
	puts("µ¡¼ÀÇ¥");
	kuku(sum);

	puts("\n\n°ö¼ÀÇ¥");
	kuku(mul);
}