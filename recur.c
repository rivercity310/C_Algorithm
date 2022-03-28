#include <stdio.h>
#include "IntStack.h"

void recur(int n) {
	if (n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

/*
[ ��� �˰����� ������� ǥ�� ]
���� ����� ����
ex) recur(n - 2)�� ������ ���� �ٲ� �� �ִ�.
- n�� n-2�� ������Ʈ�ϰ� �Լ��� ���� �������� ���ư���.
*/

void recur2_(int n) {
Top:
	if (n > 0) {
		recur2_(n - 1);
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}
}

/*
�տ��� ȣ���� ��� �Լ� ����
ex) recur(n - 1)�� ������ ���� �����Ѵ�.
- n�� n-1�� ������Ʈ�ϰ� �Լ��� ���� �������� ���ư���.
-> ������ �̿��ؼ� ���� n�� ���� ��� ������ �� �����ߴ� n�� �ٽ� ���� �� ���� ���
*/

void recur3_(int n) {
	IntStack stk;
	Initialize(&stk, 100);
Top:
	if (n > 0) {
		Push(&stk, n);
		n--;
		goto Top;
	}

	if (!isEmpty(&stk)) {
		Pop(&stk, &n);
		printf("%d\n", n);
		n -= 2;
		goto Top;
	}

	Terminate(&stk);
}

void recur_() {
	int x;
	printf("���� �Է�: ");
	scanf_s("%d", &x);
	recur3_(x);
}