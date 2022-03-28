#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
[ �ܼ� ���� ���� ]
-> ���� ������ �ִ� ��Ҹ� ��ȯ�ϹǷ� ���������� ����

���� ���� ��Һ��� �����ؼ� �˸��� ��ġ�� �ű�� ���� �˰���
���� �������� ���� �κп��� ���� ���� ���� ��Ҹ� �����ϰ�
���� �������� ���� �κ��� ù��° ��ҿ� ��ȯ�Ѵ�.
*/

void selectionSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) 
			if (a[j] < a[min])
				min = j;
		
		swap(int, a[i], a[min]);
	}
}

void selectionSort_() {
	printf("�� ��? ");
	int nx; scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", (x + i));
	}

	selectionSort(x, nx);

	for (int i = 0; i < nx; i++)
		printf("%d ", *(x + i));
	putchar('\n');
}