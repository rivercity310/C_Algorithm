/* ���� ����Ʈ�� ����ϴ� ���α׷� */
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
		"�Ӹ��� ��带 ����", "������ ��带 ����", "�Ӹ� ��� ����",
		"���� ��� ����", "������ ��� ���", "������ ��� ����",
		"��ȣ�� �˻�", "�̸����� �˻�", "��� ��� ���", "��� ��� ����"
	};

	do {
		for (i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-18.18s ", i + 1, mstring[i]);
			if (i % 3 == 2)
				putchar('\n');
		}

		printf("( 0) ���� : ");
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
			x = ScanMember("�Ӹ��� ����", MEMBER_NO | MEMBER_NAME);
			insertFront_LL(&list, &x);
			break;

		case INS_REAR:
			x = ScanMember("������ ����", MEMBER_NO | MEMBER_NAME);
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
			x = ScanMember("�˻�", MEMBER_NO);
			if (search_LL(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent_LL(&list);
			else
				puts("ã�� �� ���� �������Դϴ�.");
			break;

		case SRCH_NAME:
			x = ScanMember("�˻�", MEMBER_NAME);
			if (search_LL(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent_LL(&list);
			else
				puts("ã�� �� ���� �������Դϴ�.");
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