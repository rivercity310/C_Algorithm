#include <stdio.h>

/*
요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색 (보초법)
- 보초를 추가하면 종료 조건을 단순화시킬 수 있어서 비용 절감의 효과가 있다.
*/
int linear_search(int a[], int n, int key) {
	int i = 0;
	a[n] = key;   // 보초 추가
	
	while (1) {
		if (a[i] == key) break;
		i++;
	}

	return i == n ? -1 : i;
}

int binary_search(const int a[], int n, int key) {
	int pl = 0;
	int pr = n - 1;
	int pc;

	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key) return pc;
		else if (a[pc] < key) pl = pc + 1;
		else pr = pc - 1;
	} while (pl <= pr);

	return -1;
}

void search() {
	/*int nx, ky, idx, i;
	printf("요소 개수: "); 
	scanf_s("%d", &nx);
	int* x = calloc(nx + 1, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", &x[i]);
	}

	printf("검색값: ");
	scanf_s("%d", &ky);
	idx = linear_search(x, nx, ky);

	if (idx == -1) puts("검색 실패!");
	else printf("%d은(는) x[%d]에 있습니다.\n", ky, idx);

	free(x);*/

	int i, nx, ky, idx;
	int* x;
	puts("이진 검색");
	printf("요소 개수: ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("오름차순으로 입력\n");
	printf("x[0]: ");
	scanf_s("%d", x);

	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d]: ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}

	printf("검색값: ");
	scanf_s("%d", &ky);

	idx = binary_search(x, nx, ky);
	if (idx == -1) puts("검색 실패!");
	else printf("%d은(는) x[%d]에 있습니다.\n", ky, idx);

	free(x);
}