#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[10];
	int height, weight;
} Person;

// Person���� �� �Լ� (������������ �̸� ����)
int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

void bsearch_() {
	Person x[] = {
		{"�迵��", 211, 75},
		{"������", 201, 78},
		{"�̼���", 192, 99},
		{"������", 176, 112},
		{"������", 156, 43},
		{"ȫ����", 172, 49}
	};
	
	int nx = sizeof(x) / sizeof(x[0]);
	int retry;

	puts("�̸����� �˻��մϴ�.");
	do {
		Person temp, * p;
		printf("�̸�: ");
		scanf_s("%s", temp.name, 10);
		p = bsearch(&temp, x, nx, sizeof(Person), (int(*)(const void*, const void*)) npcmp);

		if (p == NULL) puts("�˻� ����!");
		else {
			puts("�˻� ����!");
			printf("x[%d]: %s %dcm %dkg\n", (int)(p - x), p->name, p->height, p->weight);
		}

		printf("�ٽ�? ");
		scanf_s("%d", &retry);
	} while (retry == 1);
}