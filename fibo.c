#include <stdio.h>
#define MAX_FIBO 50
int values[MAX_FIBO] = { 1, 1 };

// ��� �˰��� (��ȿ��)
size_t fib(int n) {
	return n == 0 ? 0 : (n == 1 || n == 2) ? 1 : (fib(n - 1) + fib(n - 2));
}

// �迭�� ���� �����س��� �ߺ��� ����
size_t fib2(int n) {
	if (n < 1) return 0;
	if (values[n - 1]) return values[n - 1];
	
	values[n - 1] = fib2(n - 2) + fib2(n - 1);
	return values[n - 1];
}

void fib_() {
	printf("�Ǻ���ġ: %llu\n", fib2(49));
}