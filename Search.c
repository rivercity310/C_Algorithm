#include <stdio.h>

/*
����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻� (���ʹ�)
- ���ʸ� �߰��ϸ� ���� ������ �ܼ�ȭ��ų �� �־ ��� ������ ȿ���� �ִ�.
*/
int linear_search(int a[], int n, int key) {
	int i = 0;
	a[n] = key;   // ���� �߰�
	
	while (1) {
		if (a[i] == key) break;
		i++;
	}

	return i == n ? -1 : i;
}

int binary_search(const int a[], int n, int key) {
	int pl = 0;
	int pr = n - 1;
	int pc;

	do {
		pc = (pl + pr) / 2;
		if (a[pc] == key) return pc;
		else if (a[pc] < key) pl = pc + 1;
		else pr = pc - 1;
	} while (pl <= pr);

	return -1;
}

void search() {
	/*int nx, ky, idx, i;
	printf("��� ����: "); 
	scanf_s("%d", &nx);
	int* x = calloc(nx + 1, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf_s("%d", &x[i]);
	}

	printf("�˻���: ");
	scanf_s("%d", &ky);
	idx = linear_search(x, nx, ky);

	if (idx == -1) puts("�˻� ����!");
	else printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, idx);

	free(x);*/

	int i, nx, ky, idx;
	int* x;
	puts("���� �˻�");
	printf("��� ����: ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("������������ �Է�\n");
	printf("x[0]: ");
	scanf_s("%d", x);

	for (i = 1; i < nx; i++) {
		do {
			printf("x[%d]: ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}

	printf("�˻���: ");
	scanf_s("%d", &ky);

	idx = binary_search(x, nx, ky);
	if (idx == -1) puts("�˻� ����!");
	else printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, idx);

	free(x);
}