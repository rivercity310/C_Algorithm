#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[10];
	int height, weight;
} Person;

// Person형의 비교 함수 (오름차순으로 이름 정렬)
int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

void bsearch_() {
	Person x[] = {
		{"김영준", 211, 75},
		{"박현규", 201, 78},
		{"이수진", 192, 99},
		{"최윤미", 176, 112},
		{"함진아", 156, 43},
		{"홍연의", 172, 49}
	};
	
	int nx = sizeof(x) / sizeof(x[0]);
	int retry;

	puts("이름으로 검색합니다.");
	do {
		Person temp, * p;
		printf("이름: ");
		scanf_s("%s", temp.name, 10);
		p = bsearch(&temp, x, nx, sizeof(Person), (int(*)(const void*, const void*)) npcmp);

		if (p == NULL) puts("검색 실패!");
		else {
			puts("검색 성공!");
			printf("x[%d]: %s %dcm %dkg\n", (int)(p - x), p->name, p->height, p->weight);
		}

		printf("다시? ");
		scanf_s("%d", &retry);
	} while (retry == 1);
}