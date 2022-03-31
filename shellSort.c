#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
[ �� ���� ] O(n^1.25), ���������� ����

-> �ܼ� ���� ������ ������ ������ ���� ���
���ĵ��� ���� ������ �迭�� ���� �ܼ� ���� ������ �׳� �����ϴ� ���� �ƴ϶�
"4-����", "2-����"�� �����̶� ������ �� ���¿� ����� �迭�� ����� ���� ����
���������� �ܼ� ���� ������ �����Ͽ� ������ ��ħ.

���� Ƚ���� ������ ��ü������ ����� �̵� Ƚ���� �پ��� ȿ������

������ �迭�� ��Ҹ� �׷����� ���� �� �׷� ���� �ܼ� ���� ������ �����ϰ�,
�� �׷��� ��ġ�鼭 ������ �ݺ��Ͽ� ����� �̵� Ƚ���� ���̴� ���
*/

void shellSort(int* a, int n) {
	int i, j, h;
	for (h = n / 2; h > 0; h /= 2)
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];

			a[j + h] = tmp;
		}
}

void shellSort2(int a[], int n) {
	int i, j, h;
	for (h = 1; h < n / 9; h = h * 3 + 1)
		;

	for (; h > 0; h /= 3)
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];

			a[j + h] = tmp;
		}
}

void shell_() {
	int i, nx;
	puts("[ �� ���� ]");
	printf("����� ����: "); scanf_s("%d", &nx);
	int* x = calloc(nx, sizeof(int));

	srand((unsigned int)time(NULL));

	for (i = 0; i < nx; i++) 
		*(x + i) = rand() % 365 + 1;
	

	shellSort2(x, nx);
	puts("�������� ���� �Ϸ�!");

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, *(x + i));

	free(x);
}