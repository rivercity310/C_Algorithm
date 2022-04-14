#ifndef __LinkedList
#define __LinkedList

#include "member.h"

// 노드
typedef struct __node {
	Member data;
	struct __node* next;
} Node;

// 연결 리스트
typedef struct {
	Node* head;           // 머리 노드에 대한 포인터
	Node* crnt;           // 선택한 노드에 대한 포인터
} List;

// 연결 리스트 초기화
void Initialize_LL(List* list);

// 함수 ccmpare로 x와 같은 노드 검색
Node* search_LL(List* list, const Member* x, int compare(const Member* x, const Member* y));

// 머리에 노드 삽입
void insertFront_LL(List* list, const Member* x);

// 꼬리 노드 삽입
void InsertRear_LL(List* list, const Member* x);

// 머리 노드 삭제
void RemoveFront_LL(List* list);

// 꼬리 노드 삭제
void RemoveRear_LL(List* list);

// 선택한 노드 삭제
void RemoveCurrent_LL(List* list);

// 모든 노드 삭제하기
void Clear_LL(List* list);

// 선택한 노드의 데이터 출력
void PrintCurrent_LL(const List* list);
void PrintLnCurrent_LL(const List* list);

// 모든 노드 데이터를 리스트 순으로 출력
void Print_LL(const List* list);

// 연결 리스트 종료
void Terminate_LL(List* list);

#endif
