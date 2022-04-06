#ifndef __BitSet
#define __BitSet

typedef unsigned long BitSet;

#define BitSetNull (BitSet)0;          // ������
#define BitSetBits 32                  // ��ȿ ��Ʈ ��
#define SetOf(no) ((BitSet)1 << (no))  // ���� {no}

// ���� s�� n�� �ִ��� Ȯ��
int isMember_BitSet(BitSet s, int n);

// ���� s�� n�� �߰�
void Add_BitSet(BitSet* s, int n);

// ���� s���� n�� ����
void Remove_BitSet(BitSet* s, int n);

// ���� s�� ���� ���� ��ȯ
int Size_BitSet(BitSet s);

// ���� s�� ��� ���� ���
void Print_BitSet(BitSet s);
void Println_BitSet(BitSet s);


#endif