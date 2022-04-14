/* �����ͷ� ���� ���� ����Ʈ(�ҽ�) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

// ��带 �������� �����ϴ� static �Լ�
static Node* AllocNode() {
	return calloc(1, sizeof(Node));
}

// n�� ����Ű�� ����� �� ����� ���� ����
static void SetNode_LL(Node* n, const Member* x, const Node* next) {
	n->data = *x;
	n->next = next;
}

void Initialize_LL(List* list) {
	list->head = list->crnt = NULL;
}

Node* search_LL(List* list, const Member* x, int compare(const Member* x, const Member* y)) {
	Node* ptr = list->head;

	while (ptr != NULL) {
		// Ű ���� ���� ���
		if (compare(&ptr->data, x) == 0) {
			list->crnt = ptr;
			return ptr;
		}

		ptr = ptr->next;
	}

	return NULL;
}

void insertFront_LL(List* list, const Member* x) {
	Node* ptr = list->head;
	list->head = list->crnt = AllocNode();
	SetNode_LL(list->head, x, ptr);
}

void InsertRear_LL(List* list, const Member* x) {
	// ��� �ִ� ��� �Ӹ��� �����ϸ� ��
	if (list->head == NULL)
		insertFront_LL(list, x);
	else {
		Node* ptr = list->head;
		while (ptr->next != NULL)      // ptr�� ���� ��带 ����Ű���� �ݺ�
			ptr = ptr->next;

		ptr->next = list->crnt = AllocNode();
		SetNode_LL(ptr->next, x, NULL);
	}
}

void RemoveFront_LL(List* list) {
	if (list->head != NULL) {
		Node* ptr = list->head->next;    // �ι��� ��忡 ���� ������
		free(list->head);
		list->head = list->crnt = ptr;   // ���ο� �Ӹ� ���
	}
}

void RemoveRear_LL(List* list) {
	if (list->head != NULL) {
		// ��尡 1���� ��� �Ӹ� ��� ����
		if ((list->head)->next == NULL)
			RemoveFront_LL(list);
		else {
			Node* ptr = list->head;
			Node* pre = NULL;

			/*
			while���� ����Ǹ� ptr�� ���� ��带
			pre�� ���� ����� ���� ��带 ����Ŵ
			*/
			while (ptr->next != NULL) {
				pre = ptr;
				ptr = ptr->next;
			}

			pre->next = NULL;
			free(ptr);
			list->crnt = pre;
		}
	}
}

void RemoveCurrent_LL(List* list) {
	if (list->head != NULL) {
		// �Ӹ� ��带 ������ ���¶�� �Ӹ� ��� ����
		if (list->crnt == list->head)
			RemoveFront_LL(list);
		else {
			Node* ptr = list->head;
			while (ptr->next != list->crnt)
				ptr = ptr->next;

			ptr->next = list->crnt->next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

void Clear_LL(List* list) {
	// �� �������� �Ӹ� ��� ����
	while (list->head != NULL)
		RemoveFront_LL(list);

	list->crnt = NULL;
}

void PrintCurrent_LL(const List* list) {
	if (list->crnt == NULL)
		printf("������ ��尡 �����ϴ�.");
	else
		PrintMember(&list->crnt->data);
}

void PrintLnCurrent_LL(const List* list) {
	PrintCurrent_LL(list);
	putchar('\n');
}

void Print_LL(const List* list) {
	if (list->head == NULL)
		puts("��尡 �����ϴ�.");
	else {
		Node* ptr = list->head;
		puts("[ ��� ���� ]");

		while (ptr != NULL) {
			PrintlnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

void Terminate_LL(List* list) {
	Clear_LL(list);
}