#include <stdio.h>
#include <stdbool.h>

const int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*
����
- 4�� ��� ��� 100�� ����� �����ϰ�, ������ 100�� ��� ���
400�� ����� �ٽ� ���Խ�Ų��.
*/
bool isleap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int dayofyear(int y, int m, int d) {
	int days = d;
	for (int i = 1; i < m; i++)
		days += mdays[(int)isleap(y)][i = 1];

	return days;
}

void doy() {
	int year, month, day;
	int retry;

	while (1) {
		printf("��: "); scanf_s("%d", &year);
		printf("��: "); scanf_s("%d", &month);
		printf("��: "); scanf_s("%d", &day);
		printf("%d���� %d��°�Դϴ�.\n", year, dayofyear(year, month, day));
		printf("�ٽ� �ұ��? (1/0): "); scanf_s("%d", &retry);

		if (retry == 0) return;
	};
}