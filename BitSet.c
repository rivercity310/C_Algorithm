#include <stdio.h>
#include "BitSet.h"

/*
[ ��Ʈ ���� ]
������ �ִ� ����� max�� ���� ���� ��� ������ �ϳ��� ������ ǥ���� �� �ִ�.
unsigned long�� 32��Ʈ -> ������ �����ϴ� ��Ʈ�� ����

B0 ~ B31���� ���տ� x�� ��������� Bx�� 1��, ������ 0�� �����Ͽ� ��Ÿ����.
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
	case ADD: printf("�߰��� ������: "); break;
	case RMV: printf("������ ������: "); break;
	case SCH: printf("�˻��� ������: "); break;
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

		printf("(1)s1�� �߰� (2)s1���� ���� (3)s1���� �˻� (4)s1<-s2 (5)���� ����\n"
			"(6)s2�� �߰� (7)s2���� ���� (8)s2���� �˻� (9)s2<-s1 (0)����: ");
		scanf_s("%d", &m);
		if (m == 0) break;
		
		switch (m) {
		case 1: x = scan_data_BitSet(ADD); Add_BitSet(&s1, x); break;
		case 2: x = scan_data_BitSet(RMV); Remove_BitSet(&s1, x); break;
		case 3: 
		{
			x = scan_data_BitSet(SCH); idx = isMember_BitSet(s1, x);
			printf("s1�� %d�� �����%s.\n", x, idx != 0 ? "���ϴ�" : "�� �ʽ��ϴ�");
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
			printf("s2�� %d�� �����%s.\n", x, idx != 0 ? "���ϴ�" : "�� �ʽ��ϴ�");
			break;
		}
		case 9: s2 = s1;
		}
	}
}