#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

int Initialize_Set(IntSet* s, int max) {
	s->num = 0;
	if ((s->set = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;
		return -1;
	}

	s->max = max;
	return 0;
}

int isMember_Set(const IntSet* s, int n) {
	for (int i = 0; i < s->num; i++)
		if (s->set[i] == n)
			return i;

	return -1;
}

void Add_Set(IntSet* s, int n) {
	if (s->num < s->max && isMember_Set(s, n) == -1)
		s->set[s->num++] = n;
}

void Remove_Set(IntSet* s, int n) {
	int idx;
	if ((idx = isMember_Set(s, n)) != -1) {
		s->set[idx] = s->set[--s->num];
	}
}

int Capacity_Set(const IntSet* s) {
	return s->max;
}

int Size_Set(const IntSet* s) {
	return s->num;
}

void Assign_Set(IntSet* s1, const IntSet* s2) {
	int n = s1->max < s2->num ? s1->max : s2->num;    // 복사하는 원소의 개수
	
	for (int i = 0; i < n; i++)
		s1->set[i] = s2->set[i];

	s1->num = n;
}

int Equal_Set(const IntSet* s1, const IntSet* s2) {
	if (Size_Set(s1) != Size_Set(s2)) return 0;

	int j;
	for (int i = 0; i < s1->num; i++) {
		for (j = 0; j < s2->num; j++)
			if (s1->set[i] == s2->set[j])
				break;

		if (j == s2->num) return 0;
	}

	return 1;
}

IntSet* Union_Set(IntSet* s1, const IntSet* s2, const IntSet* s3) {
	Assign_Set(s1, s2);
	for (int i = 0; i < s3->num; i++)
		Add_Set(s1, s3->set[i]);

	return s1;
}

IntSet* Intersection_Set(IntSet* s1, const IntSet* s2, const IntSet* s3) {
	s1->num = 0;     // s1을 공집합으로 만든다.
	for (int i = 0; i < s2->num; i++)
		for (int j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				Add_Set(s1, s2->set[i]);

	return s1;
}

IntSet* Difference_Set(IntSet* s1, const IntSet* s2, const IntSet* s3) {
	s1->num = 0;

	int j;
	for (int i = 0; i < s2->num; i++) {
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				break;

		if (j == s3->num)
			Add_Set(s1, s2->set[i]);
	}

	return s1;
}

void Print_Set(const IntSet* s) {
	printf("{ ");
	for (int i = 0; i < s->num; i++)
		printf("%d ", s->set[i]);
	printf("}");
}

void Println_Set(const IntSet* s) {
	Print_Set(s);
	putchar('\n');
}

void Terminate_Set(IntSet* s) {
	if (s->set != NULL) {
		free(s->set);
		s->max = s->num = 0;
	}
}

void intSet_() {
	IntSet s1, s2, s3;
	Initialize_Set(&s1, 24);
	Initialize_Set(&s2, 24);
	Initialize_Set(&s3, 24);

	Add_Set(&s1, 10);
	Add_Set(&s1, 15);
	Add_Set(&s1, 20);
	Add_Set(&s1, 25);         /* s1 = { 10, 15, 20, 25 } */

	Assign_Set(&s2, &s1);
	Add_Set(&s2, 12);
	Remove_Set(&s2, 20);	
	Assign_Set(&s3, &s2);

	printf("s1 = "); Println_Set(&s1);
	printf("s2 = "); Println_Set(&s2);
	printf("s3 = "); Println_Set(&s3);

	printf("집합 s1에 15가 들어 있%s.\n", isMember_Set(&s1, 15) > 0 ? "습니다" : "지 않습니다");
	printf("집합 s2에 25가 들어 있%s.\n", isMember_Set(&s2, 25) > 0 ? "습니다" : "지 않습니다");
	printf("집합 s1과 s2는 서로 같%s.\n", Equal_Set(&s1, &s2) ? "습니다" : "지 않습니다");
	printf("집합 s2와 s3는 서로 같%s.\n", Equal_Set(&s2, &s3) > 0 ? "습니다" : "지 않습니다");

	Terminate_Set(&s1);
	Terminate_Set(&s2);
	Terminate_Set(&s3);
}

enum {ADD, RMV, SCH};

// 데이터 입력
int scan_data(int sw) {
	int data;
	switch (sw) {
	case ADD: printf("추가할 데이터: "); break;
	case RMV: printf("삭제할 데이터: "); break;
	case SCH: printf("검색할 데이터: "); break;
	}

	scanf_s("%d", &data);
	return data;
}

void intSet2_() {
	IntSet s1, s2, temp;
	Initialize_Set(&s1, 512);
	Initialize_Set(&s2, 512);
	Initialize_Set(&temp, 512);

	while (1) {
		int m, x, idx;

		printf("s1 = "); Println_Set(&s1);
		printf("s2 = "); Println_Set(&s2);
		printf("(1)s1에 추가 (2)s1에서 삭제 (3)s1에서 검색 (4)s1<-s2\n");
		printf("(5)여러 연산 (6)s2에 추가 (7)s2에서 삭제 (8)s2에서 검색 (9) s2<-s1 (0)종료 : ");
		
		scanf_s("%d", &m);
		if (m == 0) break;

		switch (m) {
		case 1: x = scan_data(ADD); Add_Set(&s1, x); break;
		case 2: x = scan_data(RMV); Remove_Set(&s1, x); break;
		case 3: 
		{
			x = scan_data(SCH); idx = isMember_Set(&s1, x);
			printf("s1에 %d이(가) 들어 있%s.\n", x, idx >= 0 ? "습니다" : "지 않습니다"); break;
		}
		case 4: Assign_Set(&s1, &s2); break;
		case 5: 
		{
			printf("s1 == s2 = %s\n", Equal_Set(&s1, &s2) ? "true" : "false");
			printf("s1 & s2 = "); Intersection_Set(&temp, &s1, &s2); Println_Set(&temp);
			printf("s1 | s2 = "); Union_Set(&temp, &s1, &s2); Println_Set(&temp);
			printf("s1 - s2 = "); Difference_Set(&temp, &s1, &s2); Println_Set(&temp);
			break;
		}
		case 6: x = scan_data(ADD); Add_Set(&s2, x); break;
		case 7: x = scan_data(RMV); Remove_Set(&s2, x); break;
		case 8: 
		{
			x = scan_data(SCH); idx = isMember_Set(&s2, x);
			printf("s2에 %d이(가) 들어 있%s.\n", x, idx >= 0 ? "습니다" : "지 않습니다"); 
			break;
		}
		case 9: Assign_Set(&s2, &s1); break;
		}
	}

	Terminate_Set(&s1); 
	Terminate_Set(&s2); 
	Terminate_Set(&temp);
}