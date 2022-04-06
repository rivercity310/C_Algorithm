#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
[ Boyer - Moore�� ]
-> ȿ���� ����ؼ� ���� ���ڿ� �˻��� �θ� ���Ǵ� �˰���

*/

int bm_match(const char* txt, const char* pat) {
	int pt, pp;
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int skip[UCHAR_MAX + 1];        // �ǳʶٱ� ǥ

	for (pt = 0; pt <= UCHAR_MAX; pt++)
		skip[pt] = pat_len;
	for (pt = 0; pt < pat_len - 1; pt++)
		skip[pat[pt]] = pat_len - pt - 1;

	while (pt < txt_len) {
		pp = pat_len - 1;
		while (txt[pt] == pat[pp]) {
			if (pp == 0) return pt;
			pp--;
			pt--;
		}

		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
	}

	return -1;
}

void bm_() {
	char s1[256];        // �ؽ�Ʈ
	char s2[256];        // ����
	puts("Boyer-Moore��");

	printf("�ؽ�Ʈ: ");
	scanf_s("%s", s1, sizeof(s1));
	printf("����: ");
	scanf_s("%s", s2, sizeof(s2));

	int idx = bm_match(s1, s2);
	if (idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);
}