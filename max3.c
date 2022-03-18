#include <stdio.h>

/*
3개의 정수 값 가운데 '최댓값'을 구하는 알고리즘
*/

int max3(int a, int b, int c) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;

	return max;
}

/*
세 정수의 중앙값을 구하는 알고리즘
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


