#include <stdio.h>
#include <stdlib.h>

/*
[ �迭 ���� ]
=> �ð� ���⵵ O(n)

������ ��ģ �迭 a�� b�� ��Ҹ� ���� �� ���� ���� ���� ���ο� �迭�� �ִ� �۾��� �ݺ��Ͽ�
������ �����մϴ�.
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

	printf("a�� ��� ����: "); scanf_s("%d", &na);
	printf("b�� ��� ����: "); scanf_s("%d", &nb);

	int* a = (int*)malloc(na * sizeof(int));
	int* b = (int*)malloc(na * sizeof(int));
	int* c = (int*)malloc((na + nb) * sizeof(int));

	for (i = 0; i < na; i++) {
		printf("a[%d]: ", i);
		scanf_s("%d", (a + i));

		if (i >= 1 && a[i] < a[i - 1]) {
			printf("������������ �Է����ּ���!\n");
			i--;
		}
	}

	for (i = 0; i < nb; i++) {
		printf("b[%d]: ", i);
		scanf_s("%d", (b + i));

		if (i >= 1 && b[i] < b[i - 1]) {
			printf("������������ �Է����ּ���!\n");
			i--;
		}
	}

	mergeAry(a, na, b, nb, c);
	puts("�迭 a�� b�� �����Ͽ� �迭 c�� �����߽��ϴ�.");
	for (i = 0; i < na + nb; i++)
		printf("c[%d] = %d\n", i, c[i]);

	// 0��° �ε����� ���� �������� �Ҵ���� �� ������ �ƴ� ������ ������ �����ϸ� ���� �߻�!
	// (do - while ���� ����ϱ� ���� a[0] �Ǵ� b[0]�� ���� �Է¹��� ���)
	free(a); free(b); free(c);
}