#ifndef __ChainHash
#define __ChainHash

#include "Member.h"


/*
[ 체인법 ]
같은 해시 값을 갖는 데이터를 연결 리스트에 의해 사슬 모양으로 연결
배열의 각 버킷에 저장하는 값은 그 인덱스를 해시 값으로 하는 연결리스트의
첫번째 노드에 대한 포인터이다.
*/

// 버킷을 나타내는 노드
typedef struct __node {
	Member data;
	struct __node* next;
} Node;


// 해시 테이블
typedef struct {
	int size;
	Node** table;
} ChainHash;

// 해시 테이블 초기화
int Initialize_Chain(ChainHash* h, int size);

// 검색
Node* Search_Chain(const ChainHash* h, const Member* x);

// 데이터 추가
int Add_Chain(ChainHash* h, const Member* x);

// 데이터 삭제
int Remove_Chain(ChainHash* h, const Member* x);

// 해시 테이블 덤프
void Dump_Chain(const ChainHash* h);

// 모든 데이터 삭제
void Clear_Chain(ChainHash* h);

// 해시 테이블 종료
void Terminate_Chain(ChainHash* h);

#endif