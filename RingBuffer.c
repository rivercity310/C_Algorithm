#include <stdio.h>
#define N 10

/*
[ �� ������ Ȱ�� ]
�� ���۴� "������ �����͸� ������" �뵵�� ����� �� �ִ�.
�迭 a�� ��� ������ 10���̰� ��ť�� ������ �� �� ������ �迭 a�� ����Ǵ�
�����ʹ� ���� �ֱٿ� �Է��� 10���� �����͸� �� ���ۿ� �����ִ�.
*/

void RingBuffer_() {
	int a[N];
	int cnt = 0;   // �Է��� �������� ����
	int retry, i;

	puts("������ �Է��ϼ���.");
	do {
		printf("%d��° ����: ", cnt + 1);
		scanf_s("%d", &a[cnt++ % N]);

		printf("���? ");
		scanf_s("%d", &retry);
	} while (retry == 1);

	i = cnt - N;
	for (; i < cnt; i++)
		printf("%2d��° ���� = %d\n", i + 1, a[i % N]);
}


