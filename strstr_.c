#include <stdio.h>
#include <string.h>

void strstr_() {
	char s1[256], s2[256];
	char* p;

	puts("strstr �Լ�");
	printf("�ؽ�Ʈ: ");
	scanf_s("%s", s1, sizeof(s1));
	printf("����: ");
	scanf_s("%s", s2, sizeof(s2));

	p = strstr(s1, s2);        // ���ڿ� s1���� ���ڿ� s2�� �˻�
	if (!p)
		printf("�ؽ�Ʈ�� ������ �����ϴ�.\n");
	else {
		int ofs = p - s1;
		printf("\n%s\n", s1);
		printf("%*s|\n", ofs, "");
		printf("%*s%s\n", ofs, "", s2);
	}
}