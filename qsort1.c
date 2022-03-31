#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
C��� ǥ�� ���̺귯������ �����ϴ� qsort �Լ��� �̿��Ͽ�
���� �迭 �������� �����ϱ�
*/

int int_cmp(const int* a, const int* b) {
	if (*a < *b) return -1;
	else if (*a > *b) return 1;
	else return 0;
}

int qs_() {
	int i, nx;
	puts("qsort ����");
	printf("��� ����: "); scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	srand((size_t)time(NULL));

	for (i = 0; i < nx; i++)
		*(x + i) = rand() % 100 + 1;

	qsort(x,
		nx,
		sizeof(int),
		(int(*)(const void*, const void*))int_cmp
	);

	puts("�������� ����!");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}