#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

static int hash(int key, int size) {
	return key % size;
}

static void SetNode(Node* n, const Member* x, const Node* next) {
	n->data = *x;
	n->next = next;
}

/*
����� �ڷ����� Node���̰� ������ size�� �ؽ����̺� ����
*/
int Initialize_Chain(ChainHash* h, int size) {
	if ((h->table = calloc(size, sizeof(Node*))) == NULL) {
		h->size = 0;
		return 0;
	}

	h->size = size;
	for (int i = 0; i < size; i++)
		h->table[i] = NULL;

	return 1;
}

/*
1. �ؽ� �Լ� (hash)�� Ű ���� �ؽ� ������ ��ȯ
2. �ؽ� ���� �ε����� ���� ��Ŷ ����
3. ������ ��Ŷ�� ���� ����Ʈ�� ó������ ������� �˻�
*/
Node* Search_Chain(const ChainHash* h, const Member* x) {
	int key = hash(x->no, h->size);
	Node* p = h->table[key];

	while (p != NULL) {
		if (p->data.no == x->no) return p;
		p = p->next;
	}

	return NULL;
}

/*
1. �ؽ� �Լ��� Ű ���� �ؽ� ������ ��ȯ
2. �ؽ� ���� �ε����� �ϴ� ��Ŷ ����
3. ��Ŷ�� ����� �����Ͱ� ����Ű�� ���� ����Ʈ�� ó������ ������� �˻�
-> Ű ���� ���� ���� ã���� �߰� ����, ã�� ���ϸ� ����Ʈ �� �� ��ġ�� ��� ����
*/
int Add_Chain(ChainHash* h, const Member* x) {
	int key = hash(x->no, h->size);
	Node* p = h->table[key];
	Node* temp;

	while (p != NULL) {
		if (p->data.no == x->no) return 1;       // �� Ű�� �̹� ��ϵǾ����Ƿ� �߰� ����
		p = p->next;
	}

	if ((temp = calloc(1, sizeof(Node))) == NULL) return 2;

	SetNode(temp, x, h->table[key]);
	h->table[key] = temp;
	return 0; 
}

int Remove_Chain(ChainHash* h, const Member* x) {
	int key = hash(x->no, h->size);
	Node* p = h->table[key];             // ���� ������ ���
	Node** pp = &h->table[key];          // ���� ������ ��忡 ���� ������

	while (p != NULL) {
		// ã����
		if (p->data.no == x->no) { 
			*pp = p->next;
			free(p); 
			return 0;
		}

		pp = &p->next;
		p = p->next;
	}
	
	return 1;     // ���� ���� (�������� ����)
}

/*
�ؽ� ���̺��� ������ ����ϴ� Dump �Լ�
*/
void Dump_Chain(const ChainHash* h) {
	for (int i = 0; i < h->size; i++) {
		Node* p = h->table[i];
		printf("%02d  ", i);

		while (p != NULL) {
			printf("-> %d :(%s)  ", p->data.no, p->data.name);
			p = p->next;
		}

		putchar('\n');
	}
}

void Clear_Chain(ChainHash* h) {
	for (int i = 0; i < h->size; i++) {
		Node* p = h->table[i];
		while (p != NULL) {
			Node* next = p->next;
			free(p);
			p = next;
		}

		h->table[i] = NULL;
	}
}

/*
�ؽ� ���̺��� �����ϴ� Terminate �Լ�
1. Clear �Լ��� �ؽÿ� ����� ��� �����͸� �����Ѵ�.
2. Initialize �Լ��� �޸𸮿� Ȯ���� �ؽ� ���̺� �����Ѵ�.
3. �ؽ� ���̺� ũ�⸦ �����ϴ� ��� size�� 0���� �ʱ�ȭ�Ѵ�.
*/
void Terminate_Chain(ChainHash* h) {
	Clear_Chain(h);
	free(h->table);
	h->size = 0;
}