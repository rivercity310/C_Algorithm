#include <stdio.h>

/* �� �����͸� ���� ��ȯ�ϴ� �Լ� */
void swap_ptr(char** x, char** y) {
	char* temp = *x;
	*x = *y;
	*y = temp;
}

/* ���ڿ� s�� ���� */
int str_len(const char* s) {
	int len = 0;
	while (s[len]) len++;      // �ι��ڸ� ������ �ݺ� ����

	return len;
}

/* ���ڿ� s���� ���� c �˻� */
int str_chr(const char* s, int c) {
	c = (char)c;
	int i = 0;
	
	while (s[i] != c) {
		if (s[i] == '\0') return -1;      // �˻� ����
		i++;
	}

	return i;
}

int str_cmp(const char* s1, const char* s2) {
	while (*s1 == *s2) {
		if (*s1 == '\0') return 0;

		s1++;
		s2++;
	}
	
	return (unsigned char)*s1 - (unsigned char)*s2;
}


void str_() {
	char* s1 = "ABCD";
	char* s2 = "EFGH";

	swap_ptr(&s1, &s2);
	printf("%s %s\n", s1, s2);

	printf("\n\n----- ���ڿ� �˻� ------\n");
	char str[64];
	char tmp[64];
	int ch, idx;

	printf("���ڿ�: ");
	scanf_s("%s", str, sizeof(str));

	printf("�˻��� ����: ");
	scanf_s("%s", tmp, sizeof(tmp));
	ch = tmp[0];

	if ((idx = str_chr(str, ch)) == -1)
		printf("���� \'%c\'��(��) ���ڿ��� �����ϴ�.\n", ch);
	else
		printf("���� \'%c\'��(��) %d��°�� �ֽ��ϴ�.\n", ch, idx + 1);

	printf("\n\n----- ���ڿ� �� ------\n");
	char st[128];
	puts("\"ABCD\"�� ���մϴ�.");
	PUTS("\"XXXX\"�� �����մϴ�.");

	while (1) {
		printf("���ڿ� st: ");
		scanf_s("%s", st, sizeof(st));
		if (str_cmp("XXXX", str) == 0) break;

		printf("str_cmp(\"ABCD\", st) = %d\n", str_cmp("ABCD", st));
	}

}