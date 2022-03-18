#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void ary_reverse(int a[], int n) {
	for (int i = 0; i < n / 2; i++)
		swap(int, a[i], a[n - i - 1]);
}

void rev_main() {
	int nx;
	printf("요소 개수: ");
	scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	printf("%d개의 정수를 입력하세요.\n", nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", &x[i]);
	}

	ary_reverse(x, nx);
	printf("배열을 역순으로 정렬합니다.. \n");
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}