#include <stdio.h>

// 정수 값 x를 n진수로 변환하여 배열 d에 아랫자리부터 저장
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

	puts("10진수를 기수 변환합니다.");
	do {
		printf("변환하는 음이 아닌 정수: ");
		scanf_s("%u", &no);
		do {
			printf("어떤 진수로 변환할까요? (2~36) : ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd > 36);

		dno = card_convr(no, cd, cno);
		for (int i = dno - 1; i >= 0; i--)
			printf("%c", cno[i]);

		printf("입니다.\n");
		printf("한번 더? : ");
		scanf_s("%d", &retry);
	} while (retry == 1);
}