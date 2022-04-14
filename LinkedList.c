/* 포인터로 만든 연결 리스트(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

// 노드를 동적으로 생성하는 static 함수
static Node* AllocNode() {
	return calloc(1, sizeof(Node));
}

// n이 가리키는 노드의 각 멤버에 값을 설정
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
		// 키 값이 같은 경우
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
	// 비어 있는 경우 머리에 삽입하면 됨
	if (list->head == NULL)
		insertFront_LL(list, x);
	else {
		Node* ptr = list->head;
		while (ptr->next != NULL)      // ptr이 꼬리 노드를 가리키도록 반복
			ptr = ptr->next;

		ptr->next = list->crnt = AllocNode();
		SetNode_LL(ptr->next, x, NULL);
	}
}

void RemoveFront_LL(List* list) {
	if (list->head != NULL) {
		Node* ptr = list->head->next;    // 두번쨰 노드에 대한 포인터
		free(list->head);
		list->head = list->crnt = ptr;   // 새로운 머리 노드
	}
}

void RemoveRear_LL(List* list) {
	if (list->head != NULL) {
		// 노드가 1개인 경우 머리 노드 삭제
		if ((list->head)->next == NULL)
			RemoveFront_LL(list);
		else {
			Node* ptr = list->head;
			Node* pre = NULL;

			/*
			while문이 종료되면 ptr은 꼬리 노드를
			pre는 꼬리 노드의 이전 노드를 가리킴
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
		// 머리 노드를 선택한 상태라면 머리 노드 삭제
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
	// 텅 빌때까지 머리 노드 삭제
	while (list->head != NULL)
		RemoveFront_LL(list);

	list->crnt = NULL;
}

void PrintCurrent_LL(const List* list) {
	if (list->crnt == NULL)
		printf("선택한 노드가 없습니다.");
	else
		PrintMember(&list->crnt->data);
}

void PrintLnCurrent_LL(const List* list) {
	PrintCurrent_LL(list);
	putchar('\n');
}

void Print_LL(const List* list) {
	if (list->head == NULL)
		puts("노드가 없습니다.");
	else {
		Node* ptr = list->head;
		puts("[ 모두 보기 ]");

		while (ptr != NULL) {
			PrintlnMember(&ptr->data);
			ptr = ptr->next;
		}
	}
}

void Terminate_LL(List* list) {
	Clear_LL(list);
}