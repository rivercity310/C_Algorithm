#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
C언어 표준 라이브러리에서 제공하는 qsort 함수를 이용하여
정수 배열 오름차순 정렬하기
*/

int int_cmp(const int* a, const int* b) {
	if (*a < *b) return -1;
	else if (*a > *b) return 1;
	else return 0;
}

int qs_() {
	int i, nx;
	puts("qsort 정렬");
	printf("요소 개수: "); scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	srand((size_t)time(NULL));

	for (i = 0; i < nx; i++)
		*(x + i) = rand() % 100 + 1;

	qsort(x,
		nx,
		sizeof(int),
		(int(*)(const void*, const void*))int_cmp
	);

	puts("오름차순 정렬!");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}