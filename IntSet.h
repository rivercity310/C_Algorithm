#ifndef __IntSet
#define __IntSet

/* int형 집합을 관리하는 구조체 */
typedef struct {
	int max;    // 집합의 크기
	int num;    // 집합의 원소 개수
	int* set;   // 집합 본체의 배열
} IntSet;

// 집합 초기화
int Initialize_Set(IntSet* s, int max);

// 집합 s에 n이 들어 있는지 확인
int isMember_Set(const IntSet* s, int n);

// 집합 s에 n을 추가
void Add_Set(IntSet* s, int n);

// 집합 s에서 n을 삭제
void Remove_Set(IntSet* s, int n);

// 집합 s에 넣을 수 있는 최대 원소 개수
int Capacity_Set(const IntSet* s);

// 집합 s의 원소 개수
int Size_Set(const IntSet* s);

// 집합 s2를 s1에 대입
void Assign_Set(IntSet* s1, const IntSet* s2);

// 집합 s1과 s2가 같은가?
int Equal_Set(const IntSet* s1, const IntSet* s2);

// 집합 s2와 s3의 합집합을 s1에 대입
IntSet* Union_Set(IntSet* s1, const IntSet* s2, const IntSet* s3);

IntSet* Intersection_Set(IntSet* s1, const IntSet* s2, const IntSet* s3);

// 집합 s2와 s3의 교집합을 s1에 대입
IntSet* Difference_Set(IntSet* s1, const IntSet* s2, const IntSet* s3);

// 집합 s의 모든 원소 출력
void Print_Set(const IntSet* s);
void Println_Set(const IntSet* s);

// 집합 종료
void Terminate_Set(IntSet* s);

#endif