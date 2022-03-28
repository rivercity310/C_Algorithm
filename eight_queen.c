#include <stdio.h>

/*
[ 8�� ���� ] 
���� �����Ͽ� ���� �� ������ 8���� ���� 8 x 8 ü���ǿ� ����
���� ���ִ� �������� ��� �������ε� ���� �̵� ����
*/

int flag_a[8];    // �� �� üũ
int flag_b[15];   // �밢�� "/" ���� üũ
int flag_c[15];   // �ݴ� �밢�� ���� üũ
int pos[8];       // �� ������ ���� ��ġ

void print_queen() {
	for (int i = 0; i < 8; i++)
		printf("%2d", pos[i]);

	putchar('\n');
}

void set_queen(int i) {
	for (int j = 0; j < 8; j++) {
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
			pos[i] = j;
			if (i == 7) print_queen();
			else {
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
				set(i + 1);
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			}
		}
	}
}

void eight_queen_() {
	for (int i = 0; i < 8; i++) flag_a[i] = 0;
	for (int i = 0; i < 15; i++) flag_b[i] = flag_c[i] = 0;

	set(0);
}