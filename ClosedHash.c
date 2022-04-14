/*
���� �ּҹ����� ������ �ؽ�
*/

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ClosedHash.h"

// static�� ���� �����̹Ƿ� ���� �̸��� �ĺ��ڰ� ���� �ҽ� ���Ͽ� ���� ����
static int hash(int key, int size) {
	return key % size;
}

static int rehash(int key, int size) {
	return (key + 1) % size;
}

// ����� �� ����� ���� ����
static void SetBucket(Bucket* n, const Member* x, Status stat) {
	n->data = *x;
	n->stat = stat;
}



int Initialize_CH(ClosedHash* h, int size) {
	if ((h->table = calloc(size, sizeof(Bucket))) == NULL) {
		h->size = 0;
		return 0;
	}

	h->size = size;
	for (int i = 0; i < size; i++)
		h->table[i].stat = Empty;
	return 1;
}

Bucket* Search_CH(const ClosedHash* h, const Member* x) {
	int key = hash(x->no, h->size);
	Bucket* p = &h->table[key];

	for (int i = 0; p->stat != Empty && i < h->size; i++) {
		if (p->stat == Occupied && p->data.no == x->no) return p;
		
		key = rehash(key, h->size);
		p = &h->table[key];
	}

	return NULL;
}

int Add_CH(ClosedHash* h, const Member* x) {
	int key = hash(x->no, h->size);
	Bucket* p = &h->table[key];
	if (Search_CH(h, x)) return 1;          // �� Ű�� �̹� ��ϵ�

	for (int i = 0; i < h->size; i++) {
		if (p->stat == Empty || p->stat == Deleted) {
			SetBucket(p, x, Occupied);
			return 0;
		}

		key = rehash(key, h->size);
		p = &h->table[key];
	}

	return 2;       // �ؽ� ���̺��� ���� ��
}

int Remove_CH(ClosedHash* h, const Member* x) {
	Bucket* p = Search_CH(h, x);
	if (p == NULL) return 1;

	p->stat = Deleted;
	return 0;
}

void Dump_CH(const ClosedHash* h) {
	for (int i = 0; i < h->size; i++) {
		printf("%02d : ", i);
		switch (h->table[i].stat) {
		case Occupied:
			printf("%d(%s)\n", h->table[i].data.no, h->table[i].data.name);
			break;
		case Empty:
			printf("-- �̵�� --\n");
			break;
		case Deleted:
			printf("-- ���� ��ħ --\n");
			break;
		}
	}
}

void Clear_CH(ClosedHash* h) {
	for (int i = 0; i < h->size; i++)
		h->table[i].stat = Empty;
}

void Terminate_CH(ClosedHash* h) {
	Clear_CH(h);
	free(h->table);
	h->size = 0;
}





