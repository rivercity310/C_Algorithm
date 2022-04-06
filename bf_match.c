#include <stdio.h>

/*
[ 브루트 - 포스법으로 문자열 검색하기 ]
=> 선형 검색을 확장한 알고리즘으로, 이미 검사를 진행한 위치를 
기억하지 못하므로 효율이 좋지 못하다.
*/

int bf_match(const char* txt, const char* pat) {
	int pt = 0;      // txt 커서
	int pp = 0;      // pat 커서

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
	char s1[256];        // 텍스트
	char s2[256];        // 패턴
	puts("브루트-포스법");
	
	printf("텍스트: ");
	scanf_s("%s", s1, sizeof(s1));
	printf("패턴: ");
	scanf_s("%s", s2, sizeof(s2));

	int idx = bf_match(s1, s2);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);
}