#include <stdio.h>
#include <limits.h>

/* limits.h ������Ͽ����� ����� �ٷ�� */
void limits_h() {
	printf(" CHAR_BIT = %d char�� ��Ʈ�� \n", CHAR_BIT);

	puts("\n char�� ");
	printf(" CHAR_MIN = %d  signed char�� �ּڰ� \n", CHAR_MIN);
	printf(" CHAR_MAX = %d  signed char�� �ִ� \n", CHAR_MAX);


	puts("\n signed char��");

	printf(" SCHAR_MIN = %d  signed char�� �ּڰ� \n", SCHAR_MIN);
	printf(" SCHAR_MAX = %d  signed char�� �ִ� \n", SCHAR_MAX);
	printf(" UCHAR_MAX = %d  unsigned char�� �ִ� \n", UCHAR_MAX);


	puts("\n short��");

	printf(" SHRT_MIN  = %d short int �ּڰ�  \n", SHRT_MIN);
	printf(" SHRT_MAX  = %d short int �ִ�  \n", SHRT_MAX);
	printf(" USHRT_MAX = %d unsigned short int �ִ�  \n", USHRT_MAX);


	puts("\n int�� ");

	printf(" INT_MIN  = %d short int �ּڰ�  \n", INT_MIN);
	printf(" INT_MAX  = %d short int �ִ�  \n", INT_MAX);
	printf(" UINT_MAX = %u unsigned short int �ִ�  \n", UINT_MAX);

	puts("\n long�� ");

	printf(" LONG_MIN  = %d short long �ּڰ�  \n", LONG_MIN);
	printf(" LONG_MAX  = %d short long �ִ�  \n", LONG_MAX);
	printf(" ULONG_MAX = %u unsigned short long �ִ�  \n", ULONG_MAX);
}


/* ���ڿ� ���� ���ڸ� 16������ 2������ ����մϴ� */

void str_dump(const char* s) {
	do {
		printf("%c %0*X ", *s,(CHAR_BIT + 3) / 4, *s);
		for (int i = CHAR_BIT - 1; i >= 0; i--)
			putchar(((*s >> i) & 1U) ? '1' : '0');       // ���̻� U -> unsigned Ÿ��
		putchar('\n');
	} while (*s++ != '\0');
}

void str_dump_() {
	limits_h();
	str_dump("STRING");
}