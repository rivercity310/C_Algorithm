#include <stdio.h>
#include <stdlib.h>

/*
[ 버블 정렬 ]
이웃한 두 요소의 대소 관계를 비교하여 교환을 반복
*/

void bubbleSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void bSort_() {
	printf("값 몇개? ");
	int nx; scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("값: ");
		scanf_s("%d", (x + i));
	}

	bubbleSort(x, nx);
	for (int i = 0; i < nx; i++)
		printf("%d ", x[i]);
}