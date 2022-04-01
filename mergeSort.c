#include <stdio.h>
#include <stdlib.h>

/*
[ 병합 정렬 ]
=> 시간 복잡도 O(nlogn), 안정적
*/

static int* buff;     // 작업용 배열

static void __mergeSort(int a[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		int p = 0;
		int i, j = 0;
		int k = left;

		__mergeSort(a, left, center);       // 앞부분에 대한 병합정렬
		__mergeSort(a, center + 1, right);  // 뒷부분에 대한 병합정렬
	
		for (i = left; i <= center; i++)
			buff[p++] = a[i];

		while (i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];

		while (j < p)
			a[k++] = buff[j++];
	}
}

int mergeSort(int a[], int n) {
	if ((buff = calloc(n, sizeof(int))) == NULL)
		return -1;

	__mergeSort(a, 0, n - 1);
	free(buff);
	return 0;
}

void mSort_() {
	int i, nx;
	int* x;
	
	puts("병합 정렬");
	printf("요소 개수: "); scanf_s("%d", &nx);

	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", (x + i));
	}

	mergeSort(x, nx);

	puts("오름차순으로 정렬하였습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, *(x + i));

	free(x);
}