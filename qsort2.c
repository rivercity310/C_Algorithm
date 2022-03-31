#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PERSON 10

/*
qsort 함수를 사용하여 구조체 배열 정렬
*/

typedef struct {
	char name[10];
	int height;
	int weight;
} Person;

// 이름 오름차순 정렬
int npcmps(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

// 키 오름차순 정렬
int hpcmp(const Person* x, const Person* y) {
	return x->height < y->height ? -1 : x->height > y->height ? 1 : 0;
}	

// 몸무게 내림차순 정렬
int wpcmp(const Person* x, const Person* y) {
	return x->weight < y->weight ? 1 : x->weight > y->weight ? -1 : 0;
}

// 사람 no명의 데이터 출력
void print_person(const Person* x, int no) {
	for (int i = 0; i < no; i++)
		printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
}

void qs2_() {
	Person x[MAX_PERSON];
	srand((size_t)time(NULL));

	for (int i = 0; i < MAX_PERSON; i++) {
		printf("x[%d]의 이름: ", i);
		scanf_s("%s", x[i].name, sizeof(x[i].name));
		x[i].weight = rand() % 50 + 50;   // 50 ~ 99
		x[i].height = rand() % 50 + 140;  // 140 ~ 199
	}

	// 이름 오름차순 정렬
	qsort(x, MAX_PERSON, sizeof(Person), (int(*)(const void*, const void*)) npcmps);
	puts("\n이름 오름차순 정렬 후");
	print_person(x, MAX_PERSON);

	// 키 오름차순 정렬
	qsort(x, MAX_PERSON, sizeof(Person), (int(*)(const void*, const void*)) hpcmp);
	puts("\n키 오름차순 정렬 후");
	print_person(x, MAX_PERSON);

	// 몸무게 내림차순 정렬
	qsort(x, MAX_PERSON, sizeof(Person), (int(*)(const void*, const void*)) wpcmp);
	puts("\n몸무게 내림차순 정렬 후");
	print_person(x, MAX_PERSON);

}

