#include <stdio.h>

// 재귀 (비효율적)
size_t factorial(int n) {
	return n > 0 ? n * factorial(n - 1) : 1;
}

// 반복
size_t factorial2(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++)
		res *= i;

	return res;
}

void fact_() {
	printf("%llu\n", factorial(25));
	printf("%llu\n", factorial2(25));

	printf("unsigned long long의 크기: %llu\n", sizeof(unsigned long long));
	printf("size_t의 크기: %llu\n", sizeof(size_t));
}
