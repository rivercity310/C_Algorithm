#include <stdio.h>
#include "Member.h"
#include "ArrayLinkedList.h"

// 메뉴
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu_AL;

// 메뉴 선택
Menu_AL SelectMenu_AL() {
	int i, ch;
	char* mstring[] = {
		"머리에 노드 삽입", "꼬리에 노드 삽입", "머리 노드 삭제",
		"꼬리 노드 삭제", "선택한 노드 출력", "선택한 노드 삭제",
		"번호로 검색", "이름으로 검색", "모든 노드 출력",
		"모든 노드 삭제"
	};

	do {
		for (i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-18.18s ", i + 1, mstring[i]);
			if (i % 3 == 2)
				putchar('\n');
		}

		printf("(0) 종료 : ");
		scanf_s("%d", &ch);
	} while (ch < TERMINATE || ch > CLEAR);

	return (Menu_AL)ch;
}

void allt_() {
	Menu_AL menu;
	List_AL list;

	Initialize_AL(&list, 30);
	do {
		Member x;
		switch (menu = SelectMenu_AL()) {
		
		case INS_FRONT:
			x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertFront_AL(&list, &x);
			break;

		case INS_REAR:
			x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertRear_AL(&list, &x);
			break;

		case RMV_FRONT:
			RemoveFront_AL(&list);
			break;

		case RMV_REAR:
			RemoveRear_AL(&list);
			break;

		case PRINT_CRNT:
			PrintLnCurrent(&list);
			break;

		case RMV_CRNT:
			RemoveCurrent_AL(&list);
			break;

		case SRCH_NO:
			x = ScanMember("검색", MEMBER_NO);
			if (Search_AL(&list, &x, MemberNoCmp) != Null)
				PrintLnCurrent(&list);
			else
				puts("그 번호의 데이터가 없습니다.");
			break;

		case SRCH_NAME:
			x = ScanMember("검색", MEMBER_NAME);
			if (Search_AL(&list, &x, MemberNameCmp) != Null)
				PrintLnCurrent(&list);
			else
				puts("그 이름의 데이터가 없습니다.");
			break;

		case PRINT_ALL:
			Print_AL(&list);
			break;

		case CLEAR:
			Clear_AL(&list);
			break;

		}
	} while (menu != TERMINATE);

	Terminate_AL(&list);
}




