#include <stdio.h>
/*
각 행렬에 1개의 퀸을 배치하는 조합을 재귀적으로 나열
*/

typedef struct {
	int flag[8];
	int pos[8];
} Ck;

Ck ck;

void print_look() {
	for (int i = 0; i < 8; i++)
		printf("%2d", ck.pos[i]);
	putchar('\n');
}

void set_look(int i) {
	for (int j = 0; j < 8; j++) {
		if (!ck.flag[j]) {		// j행에 퀸이 배치되지 않았다면
			ck.pos[i] = j;
			if (i == 7)     // 모든 열에 배치 완료
				print_look();
		}
		else {
			ck.flag[j] = 1;
			set_look(i + 1);
			ck.flag[j] = 0;
		}
	}
}

void eight_look_() {
	for (int i = 0; i < 8; i++)
		ck.flag[i] = 0;

	set_look(0);
}