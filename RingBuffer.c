#include <stdio.h>
#define N 10

/*
[ 링 버퍼의 활용 ]
링 버퍼는 "오래된 데이터를 버리는" 용도로 사용할 수 있다.
배열 a의 요소 개수는 10개이고 인큐는 무한히 할 수 있지만 배열 a에 저장되는
데이터는 가장 최근에 입력한 10개의 데이터만 링 버퍼에 남아있다.
*/

void RingBuffer_() {
	int a[N];
	int cnt = 0;   // 입력한 데이터의 개수
	int retry, i;

	puts("정수를 입력하세요.");
	do {
		printf("%d번째 정수: ", cnt + 1);
		scanf_s("%d", &a[cnt++ % N]);

		printf("계속? ");
		scanf_s("%d", &retry);
	} while (retry == 1);

	i = cnt - N;
	for (; i < cnt; i++)
		printf("%2d번째 정수 = %d\n", i + 1, a[i % N]);
}


