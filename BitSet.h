#ifndef __BitSet
#define __BitSet

typedef unsigned long BitSet;

#define BitSetNull (BitSet)0;          // 공집합
#define BitSetBits 32                  // 유효 비트 수
#define SetOf(no) ((BitSet)1 << (no))  // 집합 {no}

// 집합 s에 n이 있는지 확인
int isMember_BitSet(BitSet s, int n);

// 집합 s에 n을 추가
void Add_BitSet(BitSet* s, int n);

// 집합 s에서 n을 삭제
void Remove_BitSet(BitSet* s, int n);

// 집합 s의 원소 개수 반환
int Size_BitSet(BitSet s);

// 집합 s의 모든 원소 출력
void Print_BitSet(BitSet s);
void Println_BitSet(BitSet s);


#endif