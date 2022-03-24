#include <stdio.h>
#include <stdbool.h>

const int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*
윤년
- 4의 배수 가운데 100의 배수를 제외하고, 제외한 100의 배수 가운데
400의 배수를 다시 포함시킨다.
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
		printf("년: "); scanf_s("%d", &year);
		printf("월: "); scanf_s("%d", &month);
		printf("일: "); scanf_s("%d", &day);
		printf("%d년의 %d일째입니다.\n", year, dayofyear(year, month, day));
		printf("다시 할까요? (1/0): "); scanf_s("%d", &retry);

		if (retry == 0) return;
	};
}