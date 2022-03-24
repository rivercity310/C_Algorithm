#ifndef __IntStack
#define __IntStack

// 스택을 구현하는 구조체
typedef struct {
	int max;		// 스택 용량
	int ptr;		// 스택 포인터
	int* stk;       // 스택의 첫 요소에 대한 포인터
} IntStack;

// 스택 초기화
int Initialize(IntStack* s, int max);

// 푸시
int Push(IntStack* s, int x);

// 팝
int Pop(IntStack* s, int* x);

// 피크
int Peek(const IntStack* s, int* x);

// 스택 비우기
void Clear(IntStack* s);

// 스택의 최대 용량
int Capacity(const IntStack* s);

// 스택의 데이터 개수
int Size(const IntStack* s);

// 비어 있나요?
int isEmpty(const IntStack* s);

// 가득 찼나요?
int isFull(const IntStack* s);

// 검색
int Search(const IntStack* s, int x);

// 모든 데이터 출력
void Print(const IntStack* s);

// 스택 종료
void Terminate(IntStack* s);

#endif