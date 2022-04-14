#ifndef __ClosedHash
#define __ClosedHash

#include "Member.h"

// 요소의 상태
typedef enum {
	Occupied, Empty, Deleted
} Status;

// 요소
typedef struct {
	Member data;
	Status stat;
} Bucket;

// 해시 테이블
typedef struct {
	int size;
	Bucket* table;        // 해시 테이블의 첫번쨰 요소에 대한 포인터
} ClosedHash;

int Initialize_CH(ClosedHash* h, int size);

Bucket* Search_CH(const ClosedHash* h, const Member* x);

int Add_CH(ClosedHash* h, const Member* x);

int Remove_CH(ClosedHash* h, const Member* x);

void Dump_CH(const ClosedHash* h);

void Clear_CH(ClosedHash* h);

void Terminate_CH(ClosedHash* h);


#endif