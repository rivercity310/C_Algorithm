#ifndef __ClosedHash
#define __ClosedHash

#include "Member.h"

// ����� ����
typedef enum {
	Occupied, Empty, Deleted
} Status;

// ���
typedef struct {
	Member data;
	Status stat;
} Bucket;

// �ؽ� ���̺�
typedef struct {
	int size;
	Bucket* table;        // �ؽ� ���̺��� ù���� ��ҿ� ���� ������
} ClosedHash;

int Initialize_CH(ClosedHash* h, int size);

Bucket* Search_CH(const ClosedHash* h, const Member* x);

int Add_CH(ClosedHash* h, const Member* x);

int Remove_CH(ClosedHash* h, const Member* x);

void Dump_CH(const ClosedHash* h);

void Clear_CH(ClosedHash* h);

void Terminate_CH(ClosedHash* h);


#endif