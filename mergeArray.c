#include <stdio.h>
#include <stdlib.h>

/*
[ 배열 병합 ]
=> 시간 복잡도 O(n)

정렬을 마친 배열 a와 b의 요소를 비교한 뒤 작은 값을 꺼내 새로운 배열에 넣는 작업을 반복하여
정렬을 수행합니다.
*/

void mergeAry(const int* a, int na, const int* b, int nb, int* c) {
	int pa = 0;
	int pb = 0;
	int pc = 0;

	while (pa < na && pb < nb)
		c[pc++] = a[pa] <= b[pb] ? a[pa++] : b[pb++];

	while (pa < na)
		c[pc++] = a[pa++];

	while (pb < nb)
		c[pc++] = b[pb++];
}

void mAry_() {
	int na, nb, i;

	printf("a의 요소 개수: "); scanf_s("%d", &na);
	printf("b의 요소 개수: "); scanf_s("%d", &nb);

	int* a = (int*)malloc(na * sizeof(int));
	int* b = (int*)malloc(na * sizeof(int));
	int* c = (int*)malloc((na + nb) * sizeof(int));

	for (i = 0; i < na; i++) {
		printf("a[%d]: ", i);
		scanf_s("%d", (a + i));

		if (i >= 1 && a[i] < a[i - 1]) {
			printf("오름차순으로 입력해주세요!\n");
			i--;
		}
	}

	for (i = 0; i < nb; i++) {
		printf("b[%d]: ", i);
		scanf_s("%d", (b + i));

		if (i >= 1 && b[i] < b[i - 1]) {
			printf("오름차순으로 입력해주세요!\n");
			i--;
		}
	}

	mergeAry(a, na, b, nb, c);
	puts("배열 a와 b를 병합하여 배열 c에 저장했습니다.");
	for (i = 0; i < na + nb; i++)
		printf("c[%d] = %d\n", i, c[i]);

	// 0번째 인덱스의 값이 동적으로 할당받은 힙 영역이 아닌 데이터 영역에 존재하면 에러 발생!
	// (do - while 문을 사용하기 위해 a[0] 또는 b[0]을 먼저 입력받은 경우)
	free(a); free(b); free(c);
}