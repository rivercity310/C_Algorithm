#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
[ 단순 선택 정렬 ]
-> 서로 떨어져 있는 요소를 교환하므로 안정적이지 않음

가장 작은 요소부터 선택해서 알맞은 위치로 옮기는 정렬 알고리즘
아직 정렬하지 않은 부분에서 값이 가장 작은 요소를 선택하고
아직 정렬하지 않은 부분의 첫번째 요소와 교환한다.
*/

void selectionSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) 
			if (a[j] < a[min])
				min = j;
		
		swap(int, a[i], a[min]);
	}
}

void selectionSort_() {
	printf("몇 개? ");
	int nx; scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", (x + i));
	}

	selectionSort(x, nx);

	for (int i = 0; i < nx; i++)
		printf("%d ", *(x + i));
	putchar('\n');
}