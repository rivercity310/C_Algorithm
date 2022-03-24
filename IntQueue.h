#ifndef __IntQueue
#define __IntQueue

typedef struct {
	int max;    // ť�� �ִ� �뷮
	int num;    // ���� ��� ���� (front�� rear�� ���� ���� ��� ť�� ����� ���� á���� �����ϱ� ����)
	int front;  // ����Ʈ
	int rear;   // ����
	int* que;   // ť�� �� �� ��ҿ� ���� ������
} IntQueue;

// ť �ʱ�ȭ
int Initialize(IntQueue* q, int max);

// ��ť
int Enque(IntQueue* q, int x);

// ��ť
int Deque(IntQueue* q, int* x);

// ��ũ
int Peek(const IntQueue* q, int* x);

// ��� ������ ����
void Clear(IntQueue* q);

// �ִ� �뷮
int Capacity(const IntQueue* q);

// ������ ����
int Size(const IntQueue* q);

// ����ִ°�?
int isEmpty(const IntQueue* q);

// ���� á�°�?
int isFull(const IntQueue* q);

// ť���� �˻�
int Search(const IntQueue* q, int x);

// ��� ������ ���
void Print(const IntQueue* q);

// ť ����
void Terminate(IntQueue* q);
#endif