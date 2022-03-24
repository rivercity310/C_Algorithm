#ifndef __IntQueue
#define __IntQueue

typedef struct {
	int max;    // 큐의 최대 용량
	int num;    // 현재 요소 개수 (front와 rear의 값이 같은 경우 큐가 빈건지 가득 찼는지 구분하기 위함)
	int front;  // 프론트
	int rear;   // 리어
	int* que;   // 큐의 맨 앞 요소에 대한 포인터
} IntQueue;

// 큐 초기화
int Initialize(IntQueue* q, int max);

// 인큐
int Enque(IntQueue* q, int x);

// 디큐
int Deque(IntQueue* q, int* x);

// 피크
int Peek(const IntQueue* q, int* x);

// 모든 데이터 삭제
void Clear(IntQueue* q);

// 최대 용량
int Capacity(const IntQueue* q);

// 데이터 개수
int Size(const IntQueue* q);

// 비어있는가?
int isEmpty(const IntQueue* q);

// 가득 찼는가?
int isFull(const IntQueue* q);

// 큐에서 검색
int Search(const IntQueue* q, int x);

// 모든 데이터 출력
void Print(const IntQueue* q);

// 큐 종료
void Terminate(IntQueue* q);
#endif