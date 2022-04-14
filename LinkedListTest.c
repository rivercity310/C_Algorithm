/* 연결 리스트를 사용하는 프로그램 */
#include <stdio.h>
#include "Member.h"
#include "LinkedList.h"

typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT, RMV_CRNT,
	SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu_LL;

Menu_LL SelectMenu_LL() {
	int i, ch;
	char* mstring[] = {
		"머리에 노드를 삽입", "꼬리에 노드를 삽입", "머리 노드 삭제",
		"꼬리 노드 삭제", "선택한 노드 출력", "선택한 노드 삭제",
		"번호로 검색", "이름으로 검색", "모든 노드 출력", "모든 노드 삭제"
	};

	do {
		for (i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-18.18s ", i + 1, mstring[i]);
			if (i % 3 == 2)
				putchar('\n');
		}

		printf("( 0) 종료 : ");
		scanf_s("%d", &ch);
	} while (ch < TERMINATE || ch > CLEAR);

	return (Menu_LL)ch;
}

void llt_() {
	Menu_LL menu;
	List list;
	Initialize_LL(&list);

	do {
		Member x;
		switch (menu = SelectMenu_LL()) {
		
		case INS_FRONT:
			x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
			insertFront_LL(&list, &x);
			break;

		case INS_REAR:
			x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertRear_LL(&list, &x);
			break;

		case RMV_FRONT:
			RemoveFront_LL(&list);
			break;

		case RMV_REAR:
			RemoveRear_LL(&list);
			break;

		case PRINT_CRNT:
			PrintLnCurrent_LL(&list);
			break;

		case RMV_CRNT:
			RemoveCurrent_LL(&list);
			break;

		case SRCH_NO:
			x = ScanMember("검색", MEMBER_NO);
			if (search_LL(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent_LL(&list);
			else
				puts("찾을 수 없는 데이터입니다.");
			break;

		case SRCH_NAME:
			x = ScanMember("검색", MEMBER_NAME);
			if (search_LL(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent_LL(&list);
			else
				puts("찾을 수 없는 데이터입니다.");
			break;

		case PRINT_ALL:
			Print_LL(&list);
			break;

		case CLEAR:
			Clear_LL(&list);
			break;
		}
	} while (menu != TERMINATE);

	Terminate_LL(&list);
}