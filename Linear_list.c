#include <stdio.h>

/*
[ ���� ����Ʈ ]
���� ����Ʈ�� �迭 ��Ҹ� �����ϰų� ������ ��
�����͸� ��� �Űܾ� �ϱ� ������ ȿ���� ���� �ʴ�.

���� ���̴� �������� ũ�⸦ �̸� �˾ƾ� �ϹǷ� ������ �ִ�.
*/

typedef struct {
	int mem_no;     // ȸ�� ��ȣ
	char* name;     // �̸�
	char* phone;    // ��ȭ��ȣ
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