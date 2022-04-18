#ifndef __ArrayLinkedList
#define __ArrayLinkedList

/*
[ 커서로 연결 리스트 만들기 ]
-> 데이터 개수가 크게 바뀌지 않고 데이터 개수의 최댓값을 미리 알 수 있는 경우

배열의 커서에 해당하는 값은 다음 노드에 대한 포인터가 아니라 다음 노드가 들어 있는
요소의 인덱스에 대한 값 (커서), 꼬리 노드의 커서는 -1
*/

#include "Member.h"

#define Null -1         // 빈 커서

typedef int Index;       // 커서의 자료형

/* 노드 */
typedef struct {
	Member data;
	Index next;        // 다음 노드
	Index Dnext;       // 프리 리스트의 다음 노드
} Node_AL;

/* 연결 리스트 */
typedef struct {
	Node_AL* n;      // 리스트 본체(배열)
	Index head;      // 머리 노드
	Index max;       // 사용 중인 꼬리 레코드
	Index deleted;   // 프리 리스트의 머리 노드
	Index crnt;      // 선택한 노드
} List_AL;



/* 연결 리스트 초기화 (가장 큰 요소 개수는 size) */
void Initialize_AL(List_AL* list, int size);

// 함수 compare로 x와 같은 노드를 검색
Index Search_AL(List_AL* list, const Member* x, int compare(const Member* x, const Member* y));

// 머리에 노드 삽입
void InsertFront_AL(List_AL* list, const Member* x);

// 꼬리에 노드 삽입
void InsertRear_AL(List_AL* list, const Member* x);

// 머리 노드 삭제
void RemoveFront_AL(List_AL* list);

// 꼬리 노드 삭제
void RemoveRear_AL(List_AL* list);

// 선택한 노드 삭제
void RemoveCurrent_AL(List_AL* list);

// 모든 노드 삭제
void Clear_AL(List_AL* list);

// 선택한 노드의 데이터 출력
void PrintCurrent(const List_AL* list);
void PrintLnCurrent(const List_AL* list);

// 모든 노드의 데이터 출력
void Print_AL(const List_AL* list);

// 연결리스트 종료
void Terminate_AL(List_AL* list);
#endif