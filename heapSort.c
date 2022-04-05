#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

/*
��: �θ��� ���� �ڽ��� ������ �׻� ũ�ų� ���� ��������Ʈ��

���� �迭�� ������ �Ʒ�, ���ʿ��� ������ ������ �����ϸ� ������ �����Ѵ�.
1. �θ�� a[(i-1) / 2]
2. ���� �ڽ��� a[i * 2 + 1]
3. ������ �ڽ��� a[i * 2 + 2]

[ �� ���� ] -> ���������� ������ �˰���, T(n) = O(nlogn)
1. ��Ʈ�� ������, �� ������ ���(������ �Ʒ�)�� ��Ʈ ��ġ�� �ű��.   a[0] <=> a[9]
2. ����� ��Ʈ�� ū ���� ������ �ڽ��� ��ġ�� �ٲٴ� ���� �ݺ��Ѵ�. 

�� ������ �ݺ��ϸ� �迭�� ���������� ū ���� ���ʴ�� ���Եȴ�.
*/



/*
a[left] - a[right]�� ������ ����� �Լ� 
a[left] �̿ܿ��� ��� �� ���¶�� �����ϰ� a[left]�� �Ʒ��κ��� �˸��� ��ġ�� �Ű� �� ���� ����
*/
static void downheap(int a[], int left, int right) {
	int temp = a[left];     // ��Ʈ
	int child, parent;

	for (parent = left; parent < (right + 1) / 2; parent = child) {
		int cl = parent * 2 + 1;        // ���� �ڽ�
		int cr = cl + 1;                // ������ �ڽ�

		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;   // ū ���� ����
		if (temp >= a[child]) break;

		a[parent] = a[child];
	}

	a[parent] = temp;
}

void heapSort(int a[], int n) {
	// �迭 a�� ������ ����
	for (int i = (n - 1) / 2; i >= 0; i--)
		downheap(a, i, n - 1);

	// ��Ʈ�� �迭�� ������ ��Ҹ� �ٲٰ� ������ �κ��� �ٽ� ������ ����� ���� �ݺ�
	for (int i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]);
		downheap(a, 0, i - 1);
	}
}

void heapSort_() {
	int nx;

	puts("�� ����");
	printf("��� ����? "); scanf_s("%d", &nx);

	int* x = (int*)malloc(sizeof(int) * nx);
	for (int i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", &x[i]);
	}

	heapSort(x, nx);
	puts("������������ ���� �Ϸ�!");
	
	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}