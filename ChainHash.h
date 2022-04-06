#ifndef __ChainHash
#define __ChainHash

#include "Member.h"


/*
[ ü�ι� ]
���� �ؽ� ���� ���� �����͸� ���� ����Ʈ�� ���� �罽 ������� ����
�迭�� �� ��Ŷ�� �����ϴ� ���� �� �ε����� �ؽ� ������ �ϴ� ���Ḯ��Ʈ��
ù��° ��忡 ���� �������̴�.
*/

// ��Ŷ�� ��Ÿ���� ���
typedef struct __node {
	Member data;
	struct __node* next;
} Node;


// �ؽ� ���̺�
typedef struct {
	int size;
	Node** table;
} ChainHash;

// �ؽ� ���̺� �ʱ�ȭ
int Initialize_Chain(ChainHash* h, int size);

// �˻�
Node* Search_Chain(const ChainHash* h, const Member* x);

// ������ �߰�
int Add_Chain(ChainHash* h, const Member* x);

// ������ ����
int Remove_Chain(ChainHash* h, const Member* x);

// �ؽ� ���̺� ����
void Dump_Chain(const ChainHash* h);

// ��� ������ ����
void Clear_Chain(ChainHash* h);

// �ؽ� ���̺� ����
void Terminate_Chain(ChainHash* h);

#endif