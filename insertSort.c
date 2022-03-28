#include <stdio.h>
#include <stdlib.h>

/*
[ 단순 삽입 정렬 ]
선택한 요소를 그보다 더 앞쪽의 알맞은 위치에 삽입하는 작업을 반복하여 정렬하는 알고리즘
단순 삽입 정렬은 2번째 요소부터 선택하여 진행한다.

=> 아직 정렬되지 않은 부분의 첫 번째 요소를 정렬된 부분의 알맞은 위치에 삽입한다.
왼쪽의 이웃한 요소가 선택한 요소보다 크면 그 값을 대입하고 앞으로 이동하면서 이 작업을 반복
그러다 선택한 값 이하의 요소를 만나면 그보다 앞쪽은 검사할 필요가 없으므로 해당 위치에 삽입할 값 대입
*/

void insertSort(int a[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int temp = a[i];
		for (j = i; j > 0 && a[j - 1] > temp; j--)
			a[j] = a[j - 1];

		a[j] = temp;
	}
}

void iSort_() {
	puts("단순 삽입 정렬");
	printf("요소 개수: ");
	int nx; scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", (x + i));
	}

	insertSort(x, nx);

	for (int i = 0; i < nx; i++)
		printf("%d ", x[i]);
	putchar('\n');
}

/*
[ 정리 ]
앞서 알아본 버블 정렬, 선택 정렬, 삽입 정렬의 시간 복잡도는 모두 O(n^2)이다. 
즉, 효율이 좋지 않다.

그 중에서 버블 정렬과 삽입 정렬은 떨어져 있는 요소들이 서로 뒤바뀌지 않아 안정적인 반면
선택 정렬은 안정적이지 않다.
*/