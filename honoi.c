#include <stdio.h>

/*
[ 과정 ] 
1. 그룹을 시작 기둥 -> 중간 기둥
2. 남은 원반 1개를 시작 기둥 -> 목표 기둥
3. 그룹을 중간 기둥 -> 목표 기둥
*/

/*
no: 옮겨야 할 원반의 개수
x: 시작 기둥의 번호
y: 목표 기둥의 번호
*/
void move(int no, int x, int y) {
	// 시작 기둥 1번, 목표 기둥 3번이므로 중간 기둥은 6 - x - y번

	if (no > 1)
		move(no - 1, x, 6 - x - y);   // 그룹을 시작 기둥에서 중간 기둥으로

	printf("원반[%d]: %d => %d\n", no, x, y);

	if (no > 1)
		move(no - 1, 6 - x - y, y);    // 그룹을 중간 기둥에서 목표 기둥으로

}

void hanoi_() {
	printf("하노이의 탑\n원반 개수: ");
	int n; scanf_s("%d", &n);
	move(n, 1, 3);
}