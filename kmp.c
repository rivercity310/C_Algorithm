#include <stdio.h>

/*
[ KMP법 ]
브루트-포스법을 개선한 알고리즘
KMP법은 검사했던 위치 결과를 버리지 않고 이를 효율적으로 활용

하지만 Boyer-Moore법과는 성능이 같거나 좋지 않아 잘 쓰이지 않음
*/

int kmp_match(const char* txt, const char* pat) {
	int pt = 1;      // txt커서
	int pp = 0;      // pat 커서
	int skip[1024];  // 건너뛰기 표

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
	char kmp1[256];        // 텍스트
	char kmp2[256];        // 패턴
	puts("KMP법");

	printf("텍스트: ");
	scanf_s("%s", kmp1, sizeof(kmp1));
	printf("패턴: ");
	scanf_s("%s", kmp2, sizeof(kmp2));

	int idx = kmp_match(kmp1, kmp2);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);
}