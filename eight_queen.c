#include <stdio.h>

/*
[ 8�� ���� ] 
���� �����Ͽ� ���� �� ������ 8���� ���� 8 x 8 ü���ǿ� ����
���� ���ִ� �������� ��� �������ε� ���� �̵� ����
*/

typedef struct {
	int flag_a[8];    // �� �� üũ
	int flag_b[15];   // �밢�� "/" ���� üũ
	int flag_c[15];   // �ݴ� �밢�� ���� üũ
	int pos[8];       // �� ������ ���� ��ġ
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