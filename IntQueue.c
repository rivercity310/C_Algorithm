#include <stdio.h>
#include <stdlib.h>

#include "IntQueue.h"

int Initialize(IntQueue* q, int max) {
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;
		return -1;
	}

	q->max = max;
	return 0;
}

int Enque(IntQueue* q, int x) {
	// Full
	if (q->num >= q->max) return -1;
	else {
		q->num++;
		q->que[q->rear++] = x;

		if (q->rear == q->max) q->rear = 0;
		return 0;
	}
}

int Deque(IntQueue* q, int* x) {
	if (q->num <= 0) return -1;
	else {
		q->num--;
		*x = q->que[q->front++];

		if (q->front == q->max) q->front = 0;
		return 0;
	}
}

int Peek(const IntQueue* q, int* x) {
	if (q->num <= 0) return -1;
	else {
		*x = q->que[q->front];
		return 0;
	}
}

void Clear(IntQueue* q) {
	q->num = q->front = q->rear = 0;
}

int Capacity(const IntQueue* q) {
	return q->max;
}

int Size(const IntQueue* q) {
	return q->num;
}

int isEmpty(const IntQueue* q) {
	return q->num <= 0;
}

int isFull(const IntQueue* q) {
	return q->num >= q->max;
}

int Search(const IntQueue* q, int x) {
	int idx;
	for (int i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;
	}

	return -1;
}

void Print(const IntQueue* q) {
	for (int i = 0; i < q->num; i++)
		printf("%d ", q->que[(i + q->front) % q->max]);
	putchar('\n');
}

void Terminate(IntQueue* q) {
	if (q->que != NULL)
		free(q->que);

	q->max = q->num = q->front = q->rear = 0;
}


void IntQueue_() {
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("ť ���� ����!");
		return;
	}

	while (1) {
		int m, x;

		printf("���� ������ ��: %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)��ť, (2)��ť, (3)��ũ, (4)���, (0)����: ");
		scanf_s("%d", &m);

		if (m == 0) break;
		switch (m) {
		case 1:
			printf("������: "); scanf_s("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a����: ��ť ����!");

			break;

		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a����: ��ť ����!");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);

			break;

		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a����: ��ũ ����!");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);

			break;

		case 4:
			Print(&que);
			break;
		}
	}

	Terminate(&que);
}