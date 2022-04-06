#include <stdio.h>

/* 두 포인터를 서로 교환하는 함수 */
void swap_ptr(char** x, char** y) {
	char* temp = *x;
	*x = *y;
	*y = temp;
}

/* 문자열 s의 길이 */
int str_len(const char* s) {
	int len = 0;
	while (s[len]) len++;      // 널문자를 만나면 반복 종료

	return len;
}

/* 문자열 s에서 문자 c 검색 */
int str_chr(const char* s, int c) {
	c = (char)c;
	int i = 0;
	
	while (s[i] != c) {
		if (s[i] == '\0') return -1;      // 검색 실패
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

	printf("\n\n----- 문자열 검색 ------\n");
	char str[64];
	char tmp[64];
	int ch, idx;

	printf("문자열: ");
	scanf_s("%s", str, sizeof(str));

	printf("검색할 문자: ");
	scanf_s("%s", tmp, sizeof(tmp));
	ch = tmp[0];

	if ((idx = str_chr(str, ch)) == -1)
		printf("문자 \'%c\'은(는) 문자열에 없습니다.\n", ch);
	else
		printf("문자 \'%c\'은(는) %d번째에 있습니다.\n", ch, idx + 1);

	printf("\n\n----- 문자열 비교 ------\n");
	char st[128];
	puts("\"ABCD\"와 비교합니다.");
	PUTS("\"XXXX\"면 종료합니다.");

	while (1) {
		printf("문자열 st: ");
		scanf_s("%s", st, sizeof(st));
		if (str_cmp("XXXX", str) == 0) break;

		printf("str_cmp(\"ABCD\", st) = %d\n", str_cmp("ABCD", st));
	}

}