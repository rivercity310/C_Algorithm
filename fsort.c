#include <stdio.h>
#include <stdlib.h>

/*
[ 도수 정렬 ] 
요소의 대소 관계를 판단하지 않고 빠르게 정렬할 수 있는 알고리즘
매우 빠르고 효율적이지만, 데이터의 최솟값과 최댓값을 미리 알고 있는 경우에만 사용할 수 있음.

1. 도수분포표 작성
2. 누적도수분포표 작성
3. 목적 배열 만들기
4. 배열 복사
*/

/* 도수 정렬 함수 (배열의 요솟값은 0 이상 max 이하 */
void fsort(int a[], int n, int max) {
	int* f = calloc(max + 1, sizeof(int));       // 누적 도수
	int* b = calloc(n, sizeof(int));             // 작업용 목적 배열

	int i;
	//for (i = 0; i <= max; i++) f[i] = 0;
	for (i = 0; i < n; i++) f[a[i]]++;
	for (i = 1; i <= max; i++) f[i] += f[i - 1];
	for (i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];   // 루프를 처음부터 돌면 안정적이지 않게 됨
	for (i = 0; i < n; i++) a[i] = b[i];

	free(b);
	free(f);
}

void fsort_() {
	const int max = 100;         // 가장 큰 값
	int nx;

	puts("도수 정렬");
	printf("요소 개수: ");
	scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	printf("0 ~ %d의 정수를 입력하세요.\n", max);

	for (int i = 0; i < nx; i++) {
		do {
			printf("x[%d]: ", i);
			scanf_s("%d", (x + i));
		} while (*(x + i) < 0 || *(x + i) > max);
	}

	fsort(x, nx, max);
	puts("오름차순으로 정렬했습니다.");

	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}