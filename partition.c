#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
[ 퀵 정렬 ]
가장 빠른 정렬 알고리즘 중 하나로 일반적으로 자주 사용됨

배열을 피벗(x)을 기준으로 두 그룹으로 나눈다.
왼쪽 커서를 pl, 오른쪽 커서를 pr로 두고
a[pl] >= x를 만족하는 요소를 찾을 때까지 pl++
a[pr] <= x를 만족하는 요소를 찾을 때까지 pr--
a[pl]과 a[pr]의 값 교환
*/

// 배열을 나누는 함수
void partition(int* a, int n) {
	int i;
	int pl = 0;      // 왼쪽 커서
	int pr = n - 1;   // 오른쪽 커서
	int x = a[n / 2];   // 피벗은 가운데 요소를 선택

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;

		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	printf("피벗: %d\n", x);
	printf("피벗 이하의 그룹\n");                // a[0] ~ a[pl - 1]
	for (i = 0; i < pl - 1; i++)
		printf("%d ", a[i]);
	putchar('\n');

	if (pl > pr + 1) {
		printf("피벗과 일치하는 그룹\n");         // a[pr + 1] ~ a[pl - 1]
		for (i = pr + 1; i <= pl - 1; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}

	printf("피벗 이상의 그룹\n");                  // a[pr + 1] ~ a[n - 1]
	for (i = pr + 1; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

void partition_test() {
	int i, nx;
	puts("배열을 나눕니다.");
	printf("요소 개수: "); scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));

	srand((size_t)time(NULL));
	for (i = 0; i < nx; i++)
		*(x + i) = rand() % 365 + 1;     // 1 ~ 365의 랜덤 정수

	partition(x, nx);
	free(x);
}