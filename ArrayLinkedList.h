#ifndef __ArrayLinkedList
#define __ArrayLinkedList

/*
[ Ŀ���� ���� ����Ʈ ����� ]
-> ������ ������ ũ�� �ٲ��� �ʰ� ������ ������ �ִ��� �̸� �� �� �ִ� ���

�迭�� Ŀ���� �ش��ϴ� ���� ���� ��忡 ���� �����Ͱ� �ƴ϶� ���� ��尡 ��� �ִ�
����� �ε����� ���� �� (Ŀ��), ���� ����� Ŀ���� -1
*/

#include "Member.h"

#define Null -1         // �� Ŀ��

typedef int Index;       // Ŀ���� �ڷ���

/* ��� */
typedef struct {
	Member data;
	Index next;        // ���� ���
	Index Dnext;       // ���� ����Ʈ�� ���� ���
} Node_AL;

/* ���� ����Ʈ */
typedef struct {
	Node_AL* n;      // ����Ʈ ��ü(�迭)
	Index head;      // �Ӹ� ���
	Index max;       // ��� ���� ���� ���ڵ�
	Index deleted;   // ���� ����Ʈ�� �Ӹ� ���
	Index crnt;      // ������ ���
} List_AL;



/* ���� ����Ʈ �ʱ�ȭ (���� ū ��� ������ size) */
void Initialize_AL(List_AL* list, int size);

// �Լ� compare�� x�� ���� ��带 �˻�
Index Search_AL(List_AL* list, const Member* x, int compare(const Member* x, const Member* y));

// �Ӹ��� ��� ����
void InsertFront_AL(List_AL* list, const Member* x);

// ������ ��� ����
void InsertRear_AL(List_AL* list, const Member* x);

// �Ӹ� ��� ����
void RemoveFront_AL(List_AL* list);

// ���� ��� ����
void RemoveRear_AL(List_AL* list);

// ������ ��� ����
void RemoveCurrent_AL(List_AL* list);

// ��� ��� ����
void Clear_AL(List_AL* list);

// ������ ����� ������ ���
void PrintCurrent(const List_AL* list);
void PrintLnCurrent(const List_AL* list);

// ��� ����� ������ ���
void Print_AL(const List_AL* list);

// ���Ḯ��Ʈ ����
void Terminate_AL(List_AL* list);
#endif