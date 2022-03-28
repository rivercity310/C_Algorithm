#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
내가 작성한 아래 코드는 선택 정렬에 가깝다.. 
*/
void bubbleSort(int* a, int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j]) {
				swap(int, a[i], a[j]);
				sum++;
			}
		}
	}

	printf("교환 횟수: %d\n", sum);
}


/*
[ 버블 정렬 ]
-> 이웃한 두 요소를 교환하므로 안정적임

이웃한 두 요소의 대소 관계를 비교하여 교환을 반복
*/

/*
[ 알고리즘 개선 1 ]
어떤 패스에서 요소의 교환 횟수가 0이면 더 이상 정렬할 요소가
없다는 뜻이므로 정렬 작업을 멈춘다
*/
void bubbleSort2(int* a, int n) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;
		for (int j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				exchg++;
			}

			sum += exchg;
		}

		// 교환이 수행되지 않았다면 정렬 멈춤
		if (exchg == 0) break;
	}

	printf("교환 횟수: %d\n", sum);

}


/*
[ 알고리즘 개선 2 ]
교환을 하다가 어떤 시점 이후에 교환이 수행되지 않는다면
그보다 앞쪽의 요소는 이미 정렬을 마친 상태이다.
*/
void bubbleSort3(int* a, int n) {
	int sum = 0;
	int k = 0;    // a[k]보다 앞쪽의 요소는 정렬을 마친 상태
	
	while (k < n - 1) {
		int last = n - 1;      // 마지막으로 교환을 수행한 위치
		for (int j = n - 1; j > k; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
				sum++;
			}
		}

		k = last;
	}

	printf("교환 횟수: %d\n", sum);
}


void bSort_() {
	printf("값 몇개? ");
	int nx; scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("값: ");
		scanf_s("%d", (x + i));
	}

	bubbleSort3(x, nx);

	for (int i = 0; i < nx; i++)
		printf("%d ", x[i]);
	putchar('\n');
}