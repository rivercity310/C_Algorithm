#include <stdio.h>
#include <stdlib.h>

/*
- void *calloc(size_t nmemb, size_t size);
크기가 size인 자료가 nmemb개만큼 들어갈 메모리를 할당
할당된 메모리 영역은 모든 비트가 0으로 초기화됨.

- void *malloc(size_t size)
크기가 size인 메모리 할당, 할당한 메모리 값은 정의되지 않음

메모리 할당에 성공하면 할당한 영역의 첫 번째 포인터 반환
*/

void Dmem() {
	int* x = calloc(10, sizeof(int));
	if (x == NULL)
		puts("메모리 할당 실패!");
	else {
		for (int i = 0; i < 10; i++) {
			printf("%d: ", i);
			scanf_s("%d", x + i);
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", x[i]);
	}
	puts("");

	free(x);
}

void Dmem2() {
	int na;
	printf("요소 개수: ");
	scanf_s("%d", &na);

	int* a = calloc(na, sizeof(int));

	if (a == NULL) puts("메모리 확보 실패!");
	else {
		printf("%d개의 정수를 입력하세요\n", na);
		for (int i = 0; i < na; i++) {
			printf("a[%d]: ", i);
			scanf_s("%d", &a[i]);
		}

		for (int i = 0; i < na; i++) {
			printf("a[%d] = %d\n", i, a[i]);
		}

		free(a);
	}
}

int maxof(const int a[], int n) {
	int max = a[0];
	for (int i = 0; i < n; i++) 
		if (a[i] > max) max = a[i];

	return max;
}

void Dmem3() {
	int number;
	printf("사람 수: ");
	scanf_s("%d", &number);

	int* height = calloc(number, sizeof(int));
	printf("%d 사람의 키를 입력하세요.\n", number);

	for (int i = 0; i < number; i++) {
		printf("height[%d]: ", i);
		scanf_s("%d", &height[i]);
	}

	printf("최댓값은 %d입니다.\n", maxof(height, number));
	free(height);
}
