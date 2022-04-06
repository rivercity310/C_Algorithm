#include <stdio.h>
#include "Member.h"
#include "ChainHash.h"

typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
} Menu;

Menu SelectMenu_() {
	int ch;
	do {
		printf("(1)추가 (2)삭제 (3)검색 (4)모두 삭제 (5)덤프 (0)종료 : ");
		scanf_s("%d", &ch);
	} while (ch < TERMINATE || ch > DUMP);

	return (Menu)ch;
}

void cht_() {
	Menu menu;
	ChainHash hash;
	Initialize_Chain(&hash, 13);       // 해시 테이블 초기화

	do {
		int result;
		Member x;
		Node* temp;

		switch (menu = SelectMenu_()) {
		case ADD:
		{
			x = ScanMember("추가", MEMBER_NO | MEMBER_NAME);
			result = Add_Chain(&hash, &x);

			if (result)
				printf("\a오류: 추가 실패! (%s).\n", (result == 1) ? "이미 등록" : "메모리 부족");
			break;
		}

		case DELETE:
		{
			x = ScanMember("삭제", MEMBER_NO);
			result = Remove_Chain(&hash, &x);

			if (result == 1)
				printf("\a오류: 이 번호의 데이터 존재하지 않음.\n");
			break;
		}

		case SEARCH:
		{
			x = ScanMember("검색", MEMBER_NO);
			temp = Search_Chain(&hash, &x);

			if (temp == NULL)
				printf("\a검색 실패!\n");
			else {
				printf("검색 성공! => ");
				PrintlnMember(&temp->data);
			}
			break;
		}

		case CLEAR:
		{
			Clear_Chain(&hash);
			break;
		}

		case DUMP:
		{
			Dump_Chain(&hash);
			break;
		}

		}
	} while (menu != TERMINATE);

	Terminate_Chain(&hash);
}