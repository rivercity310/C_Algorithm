#include <stdio.h>
#include <stdlib.h>

/*
[ ���� ���� ] 
����� ��� ���踦 �Ǵ����� �ʰ� ������ ������ �� �ִ� �˰���
�ſ� ������ ȿ����������, �������� �ּڰ��� �ִ��� �̸� �˰� �ִ� ��쿡�� ����� �� ����.

1. ��������ǥ �ۼ�
2. ������������ǥ �ۼ�
3. ���� �迭 �����
4. �迭 ����
*/

/* ���� ���� �Լ� (�迭�� ��ڰ��� 0 �̻� max ���� */
void fsort(int a[], int n, int max) {
	int* f = calloc(max + 1, sizeof(int));       // ���� ����
	int* b = calloc(n, sizeof(int));             // �۾��� ���� �迭

	int i;
	//for (i = 0; i <= max; i++) f[i] = 0;
	for (i = 0; i < n; i++) f[a[i]]++;
	for (i = 1; i <= max; i++) f[i] += f[i - 1];
	for (i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];   // ������ ó������ ���� ���������� �ʰ� ��
	for (i = 0; i < n; i++) a[i] = b[i];

	free(b);
	free(f);
}

void fsort_() {
	const int max = 100;         // ���� ū ��
	int nx;

	puts("���� ����");
	printf("��� ����: ");
	scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	printf("0 ~ %d�� ������ �Է��ϼ���.\n", max);

	for (int i = 0; i < nx; i++) {
		do {
			printf("x[%d]: ", i);
			scanf_s("%d", (x + i));
		} while (*(x + i) < 0 || *(x + i) > max);
	}

	fsort(x, nx, max);
	puts("������������ �����߽��ϴ�.");

	for (int i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}