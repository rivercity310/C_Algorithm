#include <stdio.h>
#include "BitSet.h"

/*
[ 비트 벡터 ]
집합의 최대 요소인 max의 값이 작을 경우 집합을 하나의 정수로 표현할 수 있다.
unsigned long형 32비트 -> 정수를 구성하는 비트의 나열

B0 ~ B31에서 집합에 x가 들어있으면 Bx에 1을, 없으면 0을 대입하여 나타낸다.
*/

int isMember_BitSet(BitSet s, int n) {
	return s & SetOf(n);
}

void Add_BitSet(BitSet* s, int n) {
	*s |= SetOf(n);
}

void Remove_BitSet(BitSet* s, int n) {
	*s &= ~SetOf(n); 
}

int Size_BitSet(BitSet s) {
	int n = 0;
	for (; s != (unsigned int)0; n++)
		s &= s - 1;


	return n;
}

void Print_BitSet(BitSet s) {
	printf("{ ");
	for (int i = 0; i < BitSetBits; i++)
		if (isMember_BitSet(s, i))
			printf("%d ", i);
	printf(" }");
}

void Println_BitSet(BitSet s) {
	Print_BitSet(s);
	putchar('\n');
}

enum {ADD, RMV, SCH};

int scan_data_BitSet(int sw) {
	int data;
	switch (sw) {
	case ADD: printf("추가할 데이터: "); break;
	case RMV: printf("삭제할 데이터: "); break;
	case SCH: printf("검색할 데이터: "); break;
	}

	scanf_s("%d", &data);
	return data;
}

void BitSet_() {
	BitSet s1 = BitSetNull;
	BitSet s2 = BitSetNull;

	while (1) {
		int m, x, idx;

		printf("s1 = "); Println_BitSet(s1);
		printf("s2 = "); Println_BitSet(s2);

		printf("(1)s1에 추가 (2)s1에서 삭제 (3)s1에서 검색 (4)s1<-s2 (5)여러 연산\n"
			"(6)s2에 추가 (7)s2에서 삭제 (8)s2에서 검색 (9)s2<-s1 (0)종료: ");
		scanf_s("%d", &m);
		if (m == 0) break;
		
		switch (m) {
		case 1: x = scan_data_BitSet(ADD); Add_BitSet(&s1, x); break;
		case 2: x = scan_data_BitSet(RMV); Remove_BitSet(&s1, x); break;
		case 3: 
		{
			x = scan_data_BitSet(SCH); idx = isMember_BitSet(s1, x);
			printf("s1에 %d가 들어있%s.\n", x, idx != 0 ? "습니다" : "지 않습니다");
			break;
		}
		case 4: s1 = s2; break;
		case 5:
		{
			printf("s1 == s2 = %s\n", s1 == s2 ? "true" : "false");
			printf("s1 & s2 = "); Println_BitSet(s1 & s2);
			printf("s1 | s2 = "); Println_BitSet(s1 | s2);
			printf("s1 - s2 = "); Println_BitSet(s1 & ~s2);
			break;
		}
		case 6: x = scan_data_BitSet(ADD); Add_BitSet(&s2, x); break;
		case 7: x = scan_data_BitSet(RMV); Remove_BitSet(&s2, x); break;
		case 8:
		{
			x = scan_data_BitSet(SCH); 
			idx = isMember_BitSet(s2, x);
			printf("s2에 %d가 들어있%s.\n", x, idx != 0 ? "습니다" : "지 않습니다");
			break;
		}
		case 9: s2 = s1;
		}
	}
}