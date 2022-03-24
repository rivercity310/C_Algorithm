#ifndef __IntStack
#define __IntStack

// ������ �����ϴ� ����ü
typedef struct {
	int max;		// ���� �뷮
	int ptr;		// ���� ������
	int* stk;       // ������ ù ��ҿ� ���� ������
} IntStack;

// ���� �ʱ�ȭ
int Initialize(IntStack* s, int max);

// Ǫ��
int Push(IntStack* s, int x);

// ��
int Pop(IntStack* s, int* x);

// ��ũ
int Peek(const IntStack* s, int* x);

// ���� ����
void Clear(IntStack* s);

// ������ �ִ� �뷮
int Capacity(const IntStack* s);

// ������ ������ ����
int Size(const IntStack* s);

// ��� �ֳ���?
int isEmpty(const IntStack* s);

// ���� á����?
int isFull(const IntStack* s);

// �˻�
int Search(const IntStack* s, int x);

// ��� ������ ���
void Print(const IntStack* s);

// ���� ����
void Terminate(IntStack* s);

#endif