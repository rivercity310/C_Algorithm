#ifndef __IntSet
#define __IntSet

/* int�� ������ �����ϴ� ����ü */
typedef struct {
	int max;    // ������ ũ��
	int num;    // ������ ���� ����
	int* set;   // ���� ��ü�� �迭
} IntSet;

// ���� �ʱ�ȭ
int Initialize_Set(IntSet* s, int max);

// ���� s�� n�� ��� �ִ��� Ȯ��
int isMember_Set(const IntSet* s, int n);

// ���� s�� n�� �߰�
void Add_Set(IntSet* s, int n);

// ���� s���� n�� ����
void Remove_Set(IntSet* s, int n);

// ���� s�� ���� �� �ִ� �ִ� ���� ����
int Capacity_Set(const IntSet* s);

// ���� s�� ���� ����
int Size_Set(const IntSet* s);

// ���� s2�� s1�� ����
void Assign_Set(IntSet* s1, const IntSet* s2);

// ���� s1�� s2�� ������?
int Equal_Set(const IntSet* s1, const IntSet* s2);

// ���� s2�� s3�� �������� s1�� ����
IntSet* Union_Set(IntSet* s1, const IntSet* s2, const IntSet* s3);

IntSet* Intersection_Set(IntSet* s1, const IntSet* s2, const IntSet* s3);

// ���� s2�� s3�� �������� s1�� ����
IntSet* Difference_Set(IntSet* s1, const IntSet* s2, const IntSet* s3);

// ���� s�� ��� ���� ���
void Print_Set(const IntSet* s);
void Println_Set(const IntSet* s);

// ���� ����
void Terminate_Set(IntSet* s);

#endif