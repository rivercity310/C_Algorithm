#include <stdio.h>
/*
�� ��Ŀ� 1���� ���� ��ġ�ϴ� ������ ��������� ����
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
		if (!ck.flag[j]) {		// j�࿡ ���� ��ġ���� �ʾҴٸ�
			ck.pos[i] = j;
			if (i == 7)     // ��� ���� ��ġ �Ϸ�
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