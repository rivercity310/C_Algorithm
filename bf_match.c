#include <stdio.h>

/*
[ ���Ʈ - ���������� ���ڿ� �˻��ϱ� ]
=> ���� �˻��� Ȯ���� �˰�������, �̹� �˻縦 ������ ��ġ�� 
������� ���ϹǷ� ȿ���� ���� ���ϴ�.
*/

int bf_match(const char* txt, const char* pat) {
	int pt = 0;      // txt Ŀ��
	int pp = 0;      // pat Ŀ��

	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else {
			pt = pt - pp + 1;
			pp = 0;
		}
	}

	if (pat[pp] == '\0')
		return pt - pp;

	return -1;
}

void bf_() {
	char s1[256];        // �ؽ�Ʈ
	char s2[256];        // ����
	puts("���Ʈ-������");
	
	printf("�ؽ�Ʈ: ");
	scanf_s("%s", s1, sizeof(s1));
	printf("����: ");
	scanf_s("%s", s2, sizeof(s2));

	int idx = bf_match(s1, s2);
	if (idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);
}