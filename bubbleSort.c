#include <stdio.h>
#include <stdlib.h>

/*
[ ���� ���� ]
�̿��� �� ����� ��� ���踦 ���Ͽ� ��ȯ�� �ݺ�
*/

void bubbleSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void bSort_() {
	printf("�� �? ");
	int nx; scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("��: ");
		scanf_s("%d", (x + i));
	}

	bubbleSort(x, nx);
	for (int i = 0; i < nx; i++)
		printf("%d ", x[i]);
}