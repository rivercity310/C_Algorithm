#include <stdio.h>
#include <stdbool.h>

/*
[ Algorithm 1 ]
2���� n-1������ � �����ε� ����������� ������ �Ҽ�
*/
void prime1() {
	int n, i;
	unsigned long counter = 0;   // ������ Ƚ�� ī����

	for (n = 2; n <= 1000; n++) {
		for (i = 2; i < n; i++) {
			counter++;
			if (n % i == 0) break;
		}

		// ���������� ����������� ���� -> �Ҽ�
		if (n == i)
			printf("%d\n", n);
	}

	printf("�������� ������ Ƚ�� : %lu\n", counter);
}


/*
[ Algorithm 2 ]
2���� n-1������ � �Ҽ��ε� ����������� ������ �Ҽ�
(�迭�� �̹� ���� �Ҽ��� �����صα�)
*/
void prime2() {
	int i, n;
	int prime[500];  // �Ҽ��� �����ϴ� �迭
	int ptr = 0;     // �̹� ���� �Ҽ��� ����
	unsigned long counter = 0;

	prime[ptr++] = 2;
	for (n = 3; n <= 1000; n += 2) {
		for (i = 1; i < ptr; i++) {
			counter++;
			// ����������� �Ҽ� �ƴ�
			if (n % prime[i] == 0) break;  
		}
		
		// ���������� ������ �������� �ʾҴٸ� �迭�� ����
		if (ptr == i)
			prime[ptr++] = n;
	}

	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);

	printf("�������� ������ Ƚ�� : %lu\n", counter);
}

/*
[ Algorithm 3 ]
n�� ������ ������ � �Ҽ��ε� ����������� ������ �Ҽ�
*/
void prime3() {
	int i, n;
	int prime[500];
	int ptr = 0;
	unsigned long counter = 0;
	
	prime[ptr++] = 2;
	prime[ptr++] = 3;
	for (n = 5; n <= 1000; n += 2) {
		bool flag = false;
		for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
			counter++;
			if (n % prime[i] == 0) {
				flag = !flag;
				break;
			}
		}

		if (!flag)
			prime[ptr++] = n;
	}

	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);

	printf("�������� ������ Ƚ�� : %lu\n", counter);
}