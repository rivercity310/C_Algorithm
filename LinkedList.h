#ifndef __LinkedList
#define __LinkedList

#include "member.h"

// ���
typedef struct __node {
	Member data;
	struct __node* next;
} Node;

// ���� ����Ʈ
typedef struct {
	Node* head;           // �Ӹ� ��忡 ���� ������
	Node* crnt;           // ������ ��忡 ���� ������
} List;

// ���� ����Ʈ �ʱ�ȭ
void Initialize_LL(List* list);

// �Լ� ccmpare�� x�� ���� ��� �˻�
Node* search_LL(List* list, const Member* x, int compare(const Member* x, const Member* y));

// �Ӹ��� ��� ����
void insertFront_LL(List* list, const Member* x);

// ���� ��� ����
void InsertRear_LL(List* list, const Member* x);

// �Ӹ� ��� ����
void RemoveFront_LL(List* list);

// ���� ��� ����
void RemoveRear_LL(List* list);

// ������ ��� ����
void RemoveCurrent_LL(List* list);

// ��� ��� �����ϱ�
void Clear_LL(List* list);

// ������ ����� ������ ���
void PrintCurrent_LL(const List* list);
void PrintLnCurrent_LL(const List* list);

// ��� ��� �����͸� ����Ʈ ������ ���
void Print_LL(const List* list);

// ���� ����Ʈ ����
void Terminate_LL(List* list);

#endif
