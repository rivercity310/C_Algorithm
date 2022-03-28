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
[ 재귀 알고리즘의 비재귀적 표현 ]
꼬리 재귀의 제거
ex) recur(n - 2)는 다음과 같이 바꿀 수 있다.
- n을 n-2로 업데이트하고 함수의 시작 지점으로 돌아간다.
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
앞에서 호출한 재귀 함수 제거
ex) recur(n - 1)을 다음과 같이 변경한다.
- n을 n-1로 업데이트하고 함수의 시작 지점으로 돌아간다.
-> 스택을 이용해서 변수 n의 값을 잠시 저장한 뒤 저장했던 n을 다시 꺼내 그 값을 출력
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
	printf("정수 입력: ");
	scanf_s("%d", &x);
	recur3_(x);
}