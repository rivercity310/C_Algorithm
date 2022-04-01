#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
[ �迭 ���� ]
=> �ð� ���⵵ O(n)

������ ��ģ �迭 a�� b�� ��Ҹ� ���� �� ���� ���� ���� ���ο� �迭�� �ִ� �۾��� �ݺ��Ͽ�
������ �����մϴ�.
*/

void mergeAry(const int a[], int na, const int b[], int nb, int c[]) {
	int pa = 0;
	int pb = 0;
	int pc = 0;

	while (pa < na && pb < nb)
		c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];

	while (pa < na)
		c[pc++] = a[pa++];

	while (pb < nb)
		c[pc++] = b[pb++];
}

void mAry_() {
	srand((size_t)time(NULL));
	int na, nb;

	printf("a�� ��� ����: "); scanf_s("%d", &na);
	printf("b�� ��� ����: "); scanf_s("%d", &nb);

	int* a = calloc(na, sizeof(int));
	int* b = calloc(na, sizeof(int));
	int* c = (int*)malloc((na + nb) * sizeof(int));

	printf("a[0]: "); scanf_s("%d", &a[0]);
	for (int i = 1; i < na; i++) {
		do {
			printf("a[%d]: ", i);
			scanf_s("%d", &a[i]);
		} while (a[i] < a[i - 1]);
	}

	printf("b[0]: "); scanf_s("%d", &b[0]);
	for (int i = 1; i < nb; i++) {
		do {
			printf("b[%d]: ", i);
			scanf_s("%d", &b[i]);
		} while (b[i] < b[i - 1]);
	}

	mergeAry(a, na, b, nb, c);
	puts("�迭 a�� b�� �����Ͽ� �迭 c�� �����߽��ϴ�.");
	for (int i = 0; i < na + nb; i++)
		printf("c[%d] = %d\n", i, c[i]);

	free(a); 
	free(b); 
	free(c);
}