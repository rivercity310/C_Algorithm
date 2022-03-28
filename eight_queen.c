#include <stdio.h>

/*
[ 8퀸 문제 ] 
서로 공격하여 잡을 수 없도록 8개의 퀸을 8 x 8 체스판에 놓기
퀸은 서있는 지점에서 어느 방향으로도 직선 이동 가능
*/

typedef struct {
	int flag_a[8];    // 각 행 체크
	int flag_b[15];   // 대각선 "/" 방향 체크
	int flag_c[15];   // 반대 대각선 방향 체크
	int pos[8];       // 각 열에서 퀸의 위치
} Check;

Check ck;

void print_queen() {
	for (int i = 0; i < 8; i++)
		printf("%2d", ck.pos[i] + 1);

	putchar('\n');
}

void set_queen(int i) {
	for (int j = 0; j < 8; j++) {
		if (!ck.flag_a[j] && !ck.flag_b[i + j] && !ck.flag_c[i - j + 7]) {
			ck.pos[i] = j;
			if (i == 7) print_queen();
			else {
				ck.flag_a[j] = ck.flag_b[i + j] = ck.flag_c[i - j + 7] = 1;
				set_queen(i + 1);
				ck.flag_a[j] = ck.flag_b[i + j] = ck.flag_c[i - j + 7] = 0;
			}
		}
	}
}

void eight_queen_() {
	for (int i = 0; i < 8; i++) ck.flag_a[i] = 0;
	for (int i = 0; i < 15; i++) ck.flag_b[i] = ck.flag_c[i] = 0;

	set_queen(0);
}