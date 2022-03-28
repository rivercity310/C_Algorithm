#include <stdio.h>
/*
각 행렬에 1개의 퀸을 배치하는 조합을 재귀적으로 나열
*/

int flag[8];     // 각 행 체크
int pos[8];      // 각 열에서 퀸의 위치

void print() {
	for (int i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

void set(int i) {
	for (int j = 0; j < 8; j++) {
		if (!flag[j]) {		// j행에 퀸이 배치되지 않았다면
			pos[i] = j;
			if (i == 7)     // 모든 열에 배치 완료
				print();
		}
		else {
			flag[j] = 1;
			set(i + 1);
			flag[j] = 0;
		}
	}
}

void eight_look_() {
	for (int i = 0; i < 8; i++)
		flag[i] = 0;

	set(0);
}