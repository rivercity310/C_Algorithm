#include <stdio.h>
#include <string.h>
#include <limits.h>

/*
[ Boyer - Moore법 ]
-> 효율이 우수해서 실제 문자열 검색에 널리 사용되는 알고리즘

*/

int bm_match(const char* txt, const char* pat) {
	int pt, pp;
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int skip[UCHAR_MAX + 1];        // 건너뛰기 표

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
	char s1[256];        // 텍스트
	char s2[256];        // 패턴
	puts("Boyer-Moore법");

	printf("텍스트: ");
	scanf_s("%s", s1, sizeof(s1));
	printf("패턴: ");
	scanf_s("%s", s2, sizeof(s2));

	int idx = bm_match(s1, s2);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);
}