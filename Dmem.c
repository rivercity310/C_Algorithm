#include <stdio.h>
#include <stdlib.h>

/*
- void *calloc(size_t nmemb, size_t size);
ũ�Ⱑ size�� �ڷᰡ nmemb����ŭ �� �޸𸮸� �Ҵ�
�Ҵ�� �޸� ������ ��� ��Ʈ�� 0���� �ʱ�ȭ��.

- void *malloc(size_t size)
ũ�Ⱑ size�� �޸� �Ҵ�, �Ҵ��� �޸� ���� ���ǵ��� ����

�޸� �Ҵ翡 �����ϸ� �Ҵ��� ������ ù ��° ������ ��ȯ
*/

void Dmem() {
	int* x = calloc(10, sizeof(int));
	if (x == NULL)
		puts("�޸� �Ҵ� ����!");
	else {
		for (int i = 0; i < 10; i++) {
			printf("%d: ", i);
			scanf_s("%d", x + i);
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", x[i]);
	}
	puts("");

	free(x);
}

void Dmem2() {
	int na;
	printf("��� ����: ");
	scanf_s("%d", &na);

	int* a = calloc(na, sizeof(int));

	if (a == NULL) puts("�޸� Ȯ�� ����!");
	else {
		printf("%d���� ������ �Է��ϼ���\n", na);
		for (int i = 0; i < na; i++) {
			printf("a[%d]: ", i);
			scanf_s("%d", &a[i]);
		}

		for (int i = 0; i < na; i++) {
			printf("a[%d] = %d\n", i, a[i]);
		}

		free(a);
	}
}

int maxof(const int a[], int n) {
	int max = a[0];
	for (int i = 0; i < n; i++) 
		if (a[i] > max) max = a[i];

	return max;
}

void Dmem3() {
	int number;
	printf("��� ��: ");
	scanf_s("%d", &number);

	int* height = calloc(number, sizeof(int));
	printf("%d ����� Ű�� �Է��ϼ���.\n", number);

	for (int i = 0; i < number; i++) {
		printf("height[%d]: ", i);
		scanf_s("%d", &height[i]);
	}

	printf("�ִ��� %d�Դϴ�.\n", maxof(height, number));
	free(height);
}
