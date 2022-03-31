#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PERSON 10

/*
qsort �Լ��� ����Ͽ� ����ü �迭 ����
*/

typedef struct {
	char name[10];
	int height;
	int weight;
} Person;

// �̸� �������� ����
int npcmps(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

// Ű �������� ����
int hpcmp(const Person* x, const Person* y) {
	return x->height < y->height ? -1 : x->height > y->height ? 1 : 0;
}	

// ������ �������� ����
int wpcmp(const Person* x, const Person* y) {
	return x->weight < y->weight ? 1 : x->weight > y->weight ? -1 : 0;
}

// ��� no���� ������ ���
void print_person(const Person* x, int no) {
	for (int i = 0; i < no; i++)
		printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
}

void qs2_() {
	Person x[MAX_PERSON];
	srand((size_t)time(NULL));

	for (int i = 0; i < MAX_PERSON; i++) {
		printf("x[%d]�� �̸�: ", i);
		scanf_s("%s", x[i].name, sizeof(x[i].name));
		x[i].weight = rand() % 50 + 50;   // 50 ~ 99
		x[i].height = rand() % 50 + 140;  // 140 ~ 199
	}

	// �̸� �������� ����
	qsort(x, MAX_PERSON, sizeof(Person), (int(*)(const void*, const void*)) npcmps);
	puts("\n�̸� �������� ���� ��");
	print_person(x, MAX_PERSON);

	// Ű �������� ����
	qsort(x, MAX_PERSON, sizeof(Person), (int(*)(const void*, const void*)) hpcmp);
	puts("\nŰ �������� ���� ��");
	print_person(x, MAX_PERSON);

	// ������ �������� ����
	qsort(x, MAX_PERSON, sizeof(Person), (int(*)(const void*, const void*)) wpcmp);
	puts("\n������ �������� ���� ��");
	print_person(x, MAX_PERSON);

}

