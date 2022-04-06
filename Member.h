#ifndef __Member
#define __Member

typedef struct {
	int no;
	char name[20];
} Member;

#define MEMBER_NO 1
#define MEMBER_NAME 2

// ȸ�� ��ȣ �� �Լ�
int MemberNoCmp(const Member* x, const Member* y);

// ȸ�� �̸� �� �Լ�
int MemberNameCmp(const Member* x, const Member* y);

// ȸ�� ������ ���
void PrintMember(const Member* x);
void PrintlnMember(const Member* x);

// ȸ�� ������ �о���̱�
Member ScanMember(const char* message, int sw);

#endif
