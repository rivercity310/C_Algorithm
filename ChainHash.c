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
요소의 자료형이 Node형이고 개수가 size인 해시테이블 생성
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
1. 해시 함수 (hash)가 키 값을 해시 값으로 변환
2. 해시 값을 인덱스로 갖는 버킷 선택
3. 선택한 버킷의 연결 리스트를 처음부터 순서대로 검색
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
1. 해시 함수가 키 값을 해시 값으로 변환
2. 해시 값을 인덱스로 하는 버킷 선택
3. 버킷에 저장된 포인터가 가리키는 연결 리스트를 처음부터 순서대로 검색
-> 키 값과 같은 값을 찾으면 추가 실패, 찾지 못하면 리스트 맨 앞 위치에 노드 삽입
*/
int Add_Chain(ChainHash* h, const Member* x) {
	int key = hash(x->no, h->size);
	Node* p = h->table[key];
	Node* temp;

	while (p != NULL) {
		if (p->data.no == x->no) return 1;       // 이 키는 이미 등록되었으므로 추가 실패
		p = p->next;
	}

	if ((temp = calloc(1, sizeof(Node))) == NULL) return 2;

	SetNode(temp, x, h->table[key]);
	h->table[key] = temp;
	return 0; 
}

int Remove_Chain(ChainHash* h, const Member* x) {
	int key = hash(x->no, h->size);
	Node* p = h->table[key];             // 현재 선택한 노드
	Node** pp = &h->table[key];          // 현재 선택한 노드에 대한 포인터

	while (p != NULL) {
		// 찾으면
		if (p->data.no == x->no) { 
			*pp = p->next;
			free(p); 
			return 0;
		}

		pp = &p->next;
		p = p->next;
	}
	
	return 1;     // 삭제 실패 (존재하지 않음)
}

/*
해시 테이블의 내용을 출력하는 Dump 함수
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
해시 테이블을 종료하는 Terminate 함수
1. Clear 함수로 해시에 등록한 모든 데이터를 삭제한다.
2. Initialize 함수로 메모리에 확보한 해시 테이블 해제한다.
3. 해시 테이블 크기를 저장하는 멤버 size를 0으로 초기화한다.
*/
void Terminate_Chain(ChainHash* h) {
	Clear_Chain(h);
	free(h->table);
	h->size = 0;
}