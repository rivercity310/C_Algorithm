#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
���� �ۼ��� �Ʒ� �ڵ�� ���� ���Ŀ� ������.. 
*/
void bubbleSort(int* a, int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j]) {
				swap(int, a[i], a[j]);
				sum++;
			}
		}
	}

	printf("��ȯ Ƚ��: %d\n", sum);
}


/*
[ ���� ���� ]
-> �̿��� �� ��Ҹ� ��ȯ�ϹǷ� ��������

�̿��� �� ����� ��� ���踦 ���Ͽ� ��ȯ�� �ݺ�
*/

/*
[ �˰��� ���� 1 ]
� �н����� ����� ��ȯ Ƚ���� 0�̸� �� �̻� ������ ��Ұ�
���ٴ� ���̹Ƿ� ���� �۾��� �����
*/
void bubbleSort2(int* a, int n) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;
		for (int j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				exchg++;
			}

			sum += exchg;
		}

		// ��ȯ�� ������� �ʾҴٸ� ���� ����
		if (exchg == 0) break;
	}

	printf("��ȯ Ƚ��: %d\n", sum);

}


/*
[ �˰��� ���� 2 ]
��ȯ�� �ϴٰ� � ���� ���Ŀ� ��ȯ�� ������� �ʴ´ٸ�
�׺��� ������ ��Ҵ� �̹� ������ ��ģ �����̴�.
*/
void bubbleSort3(int* a, int n) {
	int sum = 0;
	int k = 0;    // a[k]���� ������ ��Ҵ� ������ ��ģ ����
	
	while (k < n - 1) {
		int last = n - 1;      // ���������� ��ȯ�� ������ ��ġ
		for (int j = n - 1; j > k; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
				sum++;
			}
		}

		k = last;
	}

	printf("��ȯ Ƚ��: %d\n", sum);
}


void bSort_() {
	printf("�� �? ");
	int nx; scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("��: ");
		scanf_s("%d", (x + i));
	}

	bubbleSort3(x, nx);

	for (int i = 0; i < nx; i++)
		printf("%d ", x[i]);
	putchar('\n');
}