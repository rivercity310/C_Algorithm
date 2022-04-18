#include <stdio.h>
#include <stdlib.h>
#include "ArrayLinkedList.h"
#include "Member.h"

// 삽입할 레코드의 인덱스를 구한 다음 반환
static Index GetIndex(List_AL* list) {
	// 삭제할 레코드가 없는 경우
	if (list->deleted == Null)
		return ++(list->max);
	else {
		Index rec = list->deleted;
		list->deleted = list->n[rec].Dnext;
		return rec;
	}
}

// 지정된 레코드를 삭제 리스트에 등록
static void DeleteIndex(List_AL* list, Index idx) {
	// 삭제할 레코드가 없는 경우
	if (list->deleted == Null) {
		list->deleted = idx;
		list->n[idx].Dnext = Null;
	}
	else {
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].Dnext = ptr;
	}
}

// n이 가리키는 노드의 각 멤버에 값 설정
static void SetNode(Node_AL* n, const Member* x, Index next) {
	n->data = *x;
	n->next = next;
}

void Initialize_AL(List_AL* list, int size) {
	list->n = calloc(size, sizeof(Node_AL));
	list->head = list->crnt = list->max = list->deleted = Null;
}

Index Search_AL(List_AL* list, const Member* x, int compare(const Member* x, const Member* y)) {
	Index ptr = list->head;
	while (ptr != Null) {
		if (compare(&list->n[ptr].data, x) == 0) {
			list->crnt = ptr;
			return ptr;
		}

		ptr = list->n[ptr].next;
	}

	return Null;
}

void InsertFront_AL(List_AL* list, const Member* x) {
	Index ptr = list->head;
	list->head = list->crnt = GetIndex(list);
	SetNode(&list->n[list->head], x, ptr);
}

void InsertRear_AL(List_AL* list, const Member* x) {
	if (list->head == Null)
		InsertFront_AL(list, x);
	else {
		Index ptr = list->head;
		while (list->n[ptr].next != Null)
			ptr = list->n[ptr].next;

		list->n[ptr].next = list->crnt = GetIndex(list);
		SetNode(&list->n[list->n[ptr].next], x, Null);
	}
}

void RemoveFront_AL(List_AL* list) {
	if (list->head != Null) {
		Index ptr = list->n[list->head].next;
		DeleteIndex(list, list->head);
		list->head = list->crnt = ptr;
	}
}

void RemoveRear_AL(List_AL* list) {
	if (list->head != Null) {
		// 노드가 1개만 있으면 머리 노드 삭제
		if (list->n[list->head].next == Null)
			RemoveFront_AL(list);
		else {
			Index ptr = list->head;
			Index pre;

			while (list->n[ptr].next != Null) {
				pre = ptr;
				ptr = list->n[ptr].next;
			}

			list->n[pre].next = Null;
			DeleteIndex(list, ptr);
			list->crnt = pre;
		}
	}
}

void RemoveCurrent_AL(List_AL* list) {
	if (list->head != Null) {
		// 머리 노드가 선택되어 있으면 머리 노드 삭제
		if (list->crnt == list->head)
			RemoveFront_AL(list);
		else {
			Index ptr = list->head;
			while (list->n[ptr].next != list->crnt)
				ptr = list->n[ptr].next;

			list->n[ptr].next = list->n[list->crnt].next;
			DeleteIndex(list, list->crnt);
			list->crnt = ptr;
		}
	}
}

void Clear_AL(List_AL* list) {
	while (list->head != Null)
		RemoveFront_AL(list);
	
	list->crnt = Null;
}

void PrintCurrent_AL(const List_AL* list) {
	if (list->crnt == Null)
		printf("선택한 노드가 없습니다.");
	else
		PrintMember(&list->n[list->crnt].data);
}

void PrintLnCurrent_AL(const List_AL* list) {
	PrintCurrent_AL(list);
	putchar('\n');
}

void Print_AL(const List_AL* list) {
	if (list->head == Null)
		puts("노드가 없습니다.");
	else {
		Index ptr = list->head;
		puts("[ 모두 보기 ]");

		while (ptr != Null) {
			PrintLnMember(&list->n[ptr].data);
			ptr = list->n[ptr].next;
		}
	}
}

void Terminate_AL(List_AL* list) {
	Clear_AL(list);
	free(list->n);
}
