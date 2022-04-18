#include <stdio.h>
#include "Member.h"
#include "ArrayLinkedList.h"

// �޴�
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu_AL;

// �޴� ����
Menu_AL SelectMenu_AL() {
	int i, ch;
	char* mstring[] = {
		"�Ӹ��� ��� ����", "������ ��� ����", "�Ӹ� ��� ����",
		"���� ��� ����", "������ ��� ���", "������ ��� ����",
		"��ȣ�� �˻�", "�̸����� �˻�", "��� ��� ���",
		"��� ��� ����"
	};

	do {
		for (i = TERMINATE; i < CLEAR; i++) {
			printf("(%2d) %-18.18s ", i + 1, mstring[i]);
			if (i % 3 == 2)
				putchar('\n');
		}

		printf("(0) ���� : ");
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
			x = ScanMember("�Ӹ��� ����", MEMBER_NO | MEMBER_NAME);
			InsertFront_AL(&list, &x);
			break;

		case INS_REAR:
			x = ScanMember("������ ����", MEMBER_NO | MEMBER_NAME);
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
			x = ScanMember("�˻�", MEMBER_NO);
			if (Search_AL(&list, &x, MemberNoCmp) != Null)
				PrintLnCurrent(&list);
			else
				puts("�� ��ȣ�� �����Ͱ� �����ϴ�.");
			break;

		case SRCH_NAME:
			x = ScanMember("�˻�", MEMBER_NAME);
			if (Search_AL(&list, &x, MemberNameCmp) != Null)
				PrintLnCurrent(&list);
			else
				puts("�� �̸��� �����Ͱ� �����ϴ�.");
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




