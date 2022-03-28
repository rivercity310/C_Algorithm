#include <stdio.h>
/*
�� ��Ŀ� 1���� ���� ��ġ�ϴ� ������ ��������� ����
*/

int flag[8];     // �� �� üũ
int pos[8];      // �� ������ ���� ��ġ

void print() {
	for (int i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

void set(int i) {
	for (int j = 0; j < 8; j++) {
		if (!flag[j]) {		// j�࿡ ���� ��ġ���� �ʾҴٸ�
			pos[i] = j;
			if (i == 7)     // ��� ���� ��ġ �Ϸ�
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