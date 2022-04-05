#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
힙: 부모의 값이 자식의 값보다 항상 크거나 작은 완전이진트리

힙을 배열에 위에서 아래, 왼쪽에서 오른쪽 순서로 저장하면 다음을 만족한다.
1. 부모는 a[(i-1) / 2]
2. 왼쪽 자식은 a[i * 2 + 1]
3. 오른쪽 자식은 a[i * 2 + 2]

[ 힙 정렬 ] -> 선택정렬을 응용한 알고리즘, T(n) = O(nlogn)
1. 루트를 꺼내고, 맨 마지막 요소(오른쪽 아래)를 루트 위치로 옮긴다.   a[0] <=> a[9]
2. 변경된 루트와 큰 값을 가지는 자식의 위치를 바꾸는 것을 반복한다. 

위 과정을 반복하면 배열의 마지막부터 큰 값이 차례대로 대입된다.
*/



/*
a[left] - a[right]를 힙으로 만드는 함수 
a[left] 이외에는 모두 힙 상태라고 가정하고 a[left]를 아랫부분의 알맞은 위치로 옮겨 힙 상태 만듦
*/
static void downheap(int a[], int left, int right) {
	int temp = a[left];     // 루트
	int child, parent;

	for (parent = left; parent < (right + 1) / 2; parent = child) {
		int cl = parent * 2 + 1;        // 왼쪽 자식
		int cr = cl + 1;                // 오른쪽 자식

		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;   // 큰 값을 선택
		if (temp >= a[child]) break;

		a[parent] = a[child];
	}

	a[parent] = temp;
}

void heapSort(int a[], int n) {
	// 배열 a를 힙으로 만듦
	for (int i = (n - 1) / 2; i >= 0; i--)
		downheap(a, i, n - 1);

	// 루트와 배열의 마지막 요소를 바꾸고 나머지 부분을 다시 힙으로 만드는 과정 반복
	for (int i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]);
		downheap(a, 0, i - 1);
	}
}

void heapSort_() {
	int nx;

	puts("힙 정렬");
	printf("요소 개수? "); scanf_s("%d", &nx);

	int* x = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", &x[i]);
	}

	heapSort(x, nx);
	puts("오름차순으로 정렬 완료!");
	
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}