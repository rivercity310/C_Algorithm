#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
[ 셸 정렬 ] O(n^1.25), 안정적이지 않음

-> 단순 삽입 정렬의 단점을 보완한 정렬 방법
정렬되지 않은 상태의 배열에 대해 단순 삽입 정렬을 그냥 적용하는 것이 아니라
"4-정렬", "2-정렬"로 조금이라도 정렬이 된 상태에 가까운 배열로 만들어 놓은 다음
마지막으로 단순 삽입 정렬을 수행하여 정렬을 마침.

정렬 횟수는 늘지만 전체적으로 요소의 이동 횟수가 줄어들어 효율적임

정렬할 배열의 요소를 그룹으로 나눠 각 그룹 별로 단순 삽입 정렬을 수행하고,
그 그룹을 합치면서 정렬을 반복하여 요소의 이동 횟수를 줄이는 방법
*/

void shellSort(int* a, int n) {
	int i, j, h;
	for (h = n / 2; h > 0; h /= 2)
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];

			a[j + h] = tmp;
		}
}

void shellSort2(int a[], int n) {
	int i, j, h;
	for (h = 1; h < n / 9; h = h * 3 + 1)
		;

	for (; h > 0; h /= 3)
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];

			a[j + h] = tmp;
		}
}

void shell_() {
	int i, nx;
	puts("[ 셸 정렬 ]");
	printf("요소의 개수: "); scanf_s("%d", &nx);
	int* x = calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) 
		*(x + i) = rand() % 365 + 1;
	

	shellSort2(x, nx);
	puts("오름차순 정렬 완료!");

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, *(x + i));

	free(x);
}