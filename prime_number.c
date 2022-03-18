#include <stdio.h>
#include <stdbool.h>

/*
[ Algorithm 1 ]
2부터 n-1까지의 어떤 정수로도 나누어떨어지지 않으면 소수
*/
void prime1() {
	int n, i;
	unsigned long counter = 0;   // 나눗셈 횟수 카운터

	for (n = 2; n <= 1000; n++) {
		for (i = 2; i < n; i++) {
			counter++;
			if (n % i == 0) break;
		}

		// 마지막까지 나누어떨어지지 않음 -> 소수
		if (n == i)
			printf("%d\n", n);
	}

	printf("나눗셈을 실행한 횟수 : %lu\n", counter);
}


/*
[ Algorithm 2 ]
2부터 n-1까지의 어떤 소수로도 나누어떨어지지 않으면 소수
(배열에 이미 얻은 소수를 저장해두기)
*/
void prime2() {
	int i, n;
	int prime[500];  // 소수를 저장하는 배열
	int ptr = 0;     // 이미 얻은 소수의 개수
	unsigned long counter = 0;

	prime[ptr++] = 2;
	for (n = 3; n <= 1000; n += 2) {
		for (i = 1; i < ptr; i++) {
			counter++;
			// 나누어떨어지면 소수 아님
			if (n % prime[i] == 0) break;  
		}
		
		// 마지막까지 나누어 떨어지지 않았다면 배열에 저장
		if (ptr == i)
			prime[ptr++] = n;
	}

	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);

	printf("나눗셈을 실행한 횟수 : %lu\n", counter);
}

/*
[ Algorithm 3 ]
n의 제곱근 이하의 어떤 소수로도 나누어떨어지지 않으면 소수
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

	printf("나눗셈을 실행한 횟수 : %lu\n", counter);
}