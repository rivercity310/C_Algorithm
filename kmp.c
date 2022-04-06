#include <stdio.h>

/*
[ KMP�� ]
���Ʈ-�������� ������ �˰���
KMP���� �˻��ߴ� ��ġ ����� ������ �ʰ� �̸� ȿ�������� Ȱ��

������ Boyer-Moore������ ������ ���ų� ���� �ʾ� �� ������ ����
*/

int kmp_match(const char* txt, const char* pat) {
	int pt = 1;      // txtĿ��
	int pp = 0;      // pat Ŀ��
	int skip[1024];  // �ǳʶٱ� ǥ

	skip[pt] = 0;
	while (pat[pt] != '\0') {
		if (pat[pt] == pat[pp])
			skip[++pt] = ++pp;

		else if (pp == 0)
			skip[++pt] = pp;

		else
			pp = skip[pp];
	}

	pt = pp = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else if (pp == 0) {
			pt++;
		}
		else {
			pp = skip[pp];
		}
	}

	if (pat[pp] == '\0')
		return pt - pp;

	return -1;
}

void kmp_() {
	char kmp1[256];        // �ؽ�Ʈ
	char kmp2[256];        // ����
	puts("KMP��");

	printf("�ؽ�Ʈ: ");
	scanf_s("%s", kmp1, sizeof(kmp1));
	printf("����: ");
	scanf_s("%s", kmp2, sizeof(kmp2));

	int idx = kmp_match(kmp1, kmp2);
	if (idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);
}