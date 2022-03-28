#include <stdio.h>

/*
[ 유클리드 호재법 ]
두 정수의 최대공약수를 재귀적으로 구하는 방법

두 정수 22, 8 -> 22 x 8의 직사각형을 만들고
짧은 변(8)을 한 변으로 하는 정사각형으로 분할
나누어떨어질 때까지 위 과정을 재귀적으로 반복
*/

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}

void euclid_() {
	puts("두 정수의 최대공약수를 구합니다.");
	printf("정수를 입력하세요: ");
	
	int x, y;
	scanf_s("%d %d", &x, &y);
	printf("최대 공약수는 %d입니다.\n", gcd(x, y));
}