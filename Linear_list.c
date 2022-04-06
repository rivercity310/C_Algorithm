#include <stdio.h>

/*
[ 선형 리스트 ]
선형 리스트는 배열 요소를 삽입하거나 삭제할 때
데이터를 모두 옮겨야 하기 때문에 효율이 좋지 않다.

또한 쌓이는 데이터의 크기를 미리 알아야 하므로 제약이 있다.
*/

typedef struct {
	int mem_no;     // 회원 번호
	char* name;     // 이름
	char* phone;    // 전화번호
} Person;

void linear_list_() {
	Person data[] = {
		{12, "John", "111-111-1111"},
		{12, "Soo", "222-111-1111"},
		{12, "Kang", "333-111-1111"},
		{12, "Kim", "444-111-1111"}
	};

	for (int i = 0; i < 4; i++) {
		printf("%d %s %s\n", data[i].mem_no, data[i].name, data[i].phone);
	}
}