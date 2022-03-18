#include <stdio.h>

// ���� �� x�� n������ ��ȯ�Ͽ� �迭 d�� �Ʒ��ڸ����� ����
int card_convr(unsigned x, int n, char d[]) {
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;

	if (x == 0) d[digits++] = dchar[0];
	else {
		while (x) {
			d[digits++] = dchar[x % n];
			x /= n;
		}
	}

	return digits;
}

void convr_main() {
	unsigned no;
	int cd, dno;

	char cno[512];
	int retry;

	puts("10������ ��� ��ȯ�մϴ�.");
	do {
		printf("��ȯ�ϴ� ���� �ƴ� ����: ");
		scanf_s("%u", &no);
		do {
			printf("� ������ ��ȯ�ұ��? (2~36) : ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd > 36);

		dno = card_convr(no, cd, cno);
		for (int i = dno - 1; i >= 0; i--)
			printf("%c", cno[i]);

		printf("�Դϴ�.\n");
		printf("�ѹ� ��? : ");
		scanf_s("%d", &retry);
	} while (retry == 1);
}