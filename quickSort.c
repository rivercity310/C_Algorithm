#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "intStack.h"
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void quickSort2(int a[], int left, int right);


/*
[ 퀵 정렬 ]
O(nlogn), 최악의 경우 O(n^2)

요소의 개수가 1이 될 때까지 그룹을 나눈다.
1. pr이 a[0]보다 오른쪽에 있으면 (left < pr) 왼쪽 그룹을 나눈다.
2. pl이 a[n]보다 왼쪽에 있으면 (pl < right) 오른쪽 그룹을 나눈다.

퀵 정렬은 분할 정복 알고리즘이므로 재귀를 사용하여 구현할 수 있다.
*/

void quickSort(int a[], int left, int right) {
	int pl = left;    // 왼쪽 커서
	int pr = right;   // 오른쪽 커서
	int x = a[(pl + pr) / 2];   // 피벗 (가운데 요소)

	// 분할 과정 출력하기
	printf("a[%d] ~ a[%d] : {", left, right);
	for (int i = left; i < right; i++)
		printf("%d, ", a[i]);
	printf("%d}\n", a[right]);
	
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;

		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) quickSort(a, left, pr);
	if (pl < right) quickSort(a, pl, right);
}

void quickSort_() {
	int i, nx;
	puts("퀵 정렬");
	printf("요소 개수: "); scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	srand((size_t)time(NULL));

	for (i = 0; i < nx; i++)
		*(x + i) = rand() % 365 + 1;

	quickSort2(x, 0, nx - 1);
	puts("오름차순 정렬!!");

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}


// 비재귀적인 퀵정렬
void quickSort2(int a[], int left, int right) {
	IntStack lstack;        // 나눌 범위의 왼쪽 끝 요소의 인덱스를 저장하는 스택
	IntStack rstack;        // 나눌 범위의 오른쪽 끝 요소의 인덱스를 저장하는 스택

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!isEmpty(&lstack)) {
		/*
			int a = (1, 2)를 풀어쓰면 다음 코드와 같다
			
			int a = 1;
			a = 2;
		*/
		int pl = (Pop(&lstack, &left), left);    // lstack에서 팝한 값을 left에 대입한 다음 그 값을 다시 pl에 대입
		int pr = (Pop(&rstack, &right), right);
		int x = a[(left + right) / 2];

		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;

			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);
		}

		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);
		}
	}

	Terminate(&lstack);
	Terminate(&rstack);
}