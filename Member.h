#ifndef __Member
#define __Member

typedef struct {
	int no;
	char name[20];
} Member;

#define MEMBER_NO 1
#define MEMBER_NAME 2

// 회원 번호 비교 함수
int MemberNoCmp(const Member* x, const Member* y);

// 회원 이름 비교 함수
int MemberNameCmp(const Member* x, const Member* y);

// 회원 데이터 출력
void PrintMember(const Member* x);
void PrintlnMember(const Member* x);

// 회원 데이터 읽어들이기
Member ScanMember(const char* message, int sw);

#endif
