#include <stdio.h>
#include "Member.h"
#include "ChainHash.h"

typedef enum {
	TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
} Menu;

Menu SelectMenu_() {
	int ch;
	do {
		printf("(1)�߰� (2)���� (3)�˻� (4)��� ���� (5)���� (0)���� : ");
		scanf_s("%d", &ch);
	} while (ch < TERMINATE || ch > DUMP);

	return (Menu)ch;
}

void cht_() {
	Menu menu;
	ChainHash hash;
	Initialize_Chain(&hash, 13);       // �ؽ� ���̺� �ʱ�ȭ

	do {
		int result;
		Member x;
		Node* temp;

		switch (menu = SelectMenu_()) {
		case ADD:
		{
			x = ScanMember("�߰�", MEMBER_NO | MEMBER_NAME);
			result = Add_Chain(&hash, &x);

			if (result)
				printf("\a����: �߰� ����! (%s).\n", (result == 1) ? "�̹� ���" : "�޸� ����");
			break;
		}

		case DELETE:
		{
			x = ScanMember("����", MEMBER_NO);
			result = Remove_Chain(&hash, &x);

			if (result == 1)
				printf("\a����: �� ��ȣ�� ������ �������� ����.\n");
			break;
		}

		case SEARCH:
		{
			x = ScanMember("�˻�", MEMBER_NO);
			temp = Search_Chain(&hash, &x);

			if (temp == NULL)
				printf("\a�˻� ����!\n");
			else {
				printf("�˻� ����! => ");
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