#include <stdio.h>

/*
3���� ���� �� ��� '�ִ�'�� ���ϴ� �˰���
*/

int max3(int a, int b, int c) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;

	return max;
}

/*
�� ������ �߾Ӱ��� ���ϴ� �˰���
*/

int med3(int a, int b, int c) {
	if (a >= b)
		if (b >= c) return b;
		else if (a <= c) return a;
		else return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else return b;
}


