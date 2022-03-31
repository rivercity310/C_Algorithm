#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "intStack.h"
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void quickSort2(int a[], int left, int right);


/*
[ �� ���� ]
O(nlogn), �־��� ��� O(n^2)

����� ������ 1�� �� ������ �׷��� ������.
1. pr�� a[0]���� �����ʿ� ������ (left < pr) ���� �׷��� ������.
2. pl�� a[n]���� ���ʿ� ������ (pl < right) ������ �׷��� ������.

�� ������ ���� ���� �˰����̹Ƿ� ��͸� ����Ͽ� ������ �� �ִ�.
*/

void quickSort(int a[], int left, int right) {
	int pl = left;    // ���� Ŀ��
	int pr = right;   // ������ Ŀ��
	int x = a[(pl + pr) / 2];   // �ǹ� (��� ���)

	// ���� ���� ����ϱ�
	printf("a[%d] ~ a[%d] : {", left, right);
	for (int i = left; i < right; i++)
		printf("%d, ", a[i]);
	printf("%d}\n", a[right]);
	
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;

		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) quickSort(a, left, pr);
	if (pl < right) quickSort(a, pl, right);
}

void quickSort_() {
	int i, nx;
	puts("�� ����");
	printf("��� ����: "); scanf_s("%d", &nx);

	int* x = calloc(nx, sizeof(int));
	srand((size_t)time(NULL));

	for (i = 0; i < nx; i++)
		*(x + i) = rand() % 365 + 1;

	quickSort2(x, 0, nx - 1);
	puts("�������� ����!!");

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
}


// ��������� ������
void quickSort2(int a[], int left, int right) {
	IntStack lstack;        // ���� ������ ���� �� ����� �ε����� �����ϴ� ����
	IntStack rstack;        // ���� ������ ������ �� ����� �ε����� �����ϴ� ����

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!isEmpty(&lstack)) {
		/*
			int a = (1, 2)�� Ǯ��� ���� �ڵ�� ����
			
			int a = 1;
			a = 2;
		*/
		int pl = (Pop(&lstack, &left), left);    // lstack���� ���� ���� left�� ������ ���� �� ���� �ٽ� pl�� ����
		int pr = (Pop(&rstack, &right), right);
		int x = a[(left + right) / 2];

		do {
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;

			if (pl <= pr) {
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl <= pr);

		if (left < pr) {
			Push(&lstack, left);
			Push(&rstack, pr);
		}

		if (pl < right) {
			Push(&lstack, pl);
			Push(&rstack, right);
		}
	}

	Terminate(&lstack);
	Terminate(&rstack);
}