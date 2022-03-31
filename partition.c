#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
[ �� ���� ]
���� ���� ���� �˰��� �� �ϳ��� �Ϲ������� ���� ����

�迭�� �ǹ�(x)�� �������� �� �׷����� ������.
���� Ŀ���� pl, ������ Ŀ���� pr�� �ΰ�
a[pl] >= x�� �����ϴ� ��Ҹ� ã�� ������ pl++
a[pr] <= x�� �����ϴ� ��Ҹ� ã�� ������ pr--
a[pl]�� a[pr]�� �� ��ȯ
*/

// �迭�� ������ �Լ�
void partition(int* a, int n) {
	int i;
	int pl = 0;      // ���� Ŀ��
	int pr = n - 1;   // ������ Ŀ��
	int x = a[n / 2];   // �ǹ��� ��� ��Ҹ� ����

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;

		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	printf("�ǹ�: %d\n", x);
	printf("�ǹ� ������ �׷�\n");                // a[0] ~ a[pl - 1]
	for (i = 0; i < pl - 1; i++)
		printf("%d ", a[i]);
	putchar('\n');

	if (pl > pr + 1) {
		printf("�ǹ��� ��ġ�ϴ� �׷�\n");         // a[pr + 1] ~ a[pl - 1]
		for (i = pr + 1; i <= pl - 1; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}

	printf("�ǹ� �̻��� �׷�\n");                  // a[pr + 1] ~ a[n - 1]
	for (i = pr + 1; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

void partition_test() {
	int i, nx;
	puts("�迭�� �����ϴ�.");
	printf("��� ����: "); scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));

	srand((size_t)time(NULL));
	for (i = 0; i < nx; i++)
		*(x + i) = rand() % 365 + 1;     // 1 ~ 365�� ���� ����

	partition(x, nx);
	free(x);
}