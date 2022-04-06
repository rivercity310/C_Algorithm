#include <stdio.h>
#include <limits.h>

/* limits.h 헤더파일에서는 상수를 다룬다 */
void limits_h() {
	printf(" CHAR_BIT = %d char의 비트수 \n", CHAR_BIT);

	puts("\n char형 ");
	printf(" CHAR_MIN = %d  signed char의 최솟값 \n", CHAR_MIN);
	printf(" CHAR_MAX = %d  signed char의 최댓값 \n", CHAR_MAX);


	puts("\n signed char형");

	printf(" SCHAR_MIN = %d  signed char의 최솟값 \n", SCHAR_MIN);
	printf(" SCHAR_MAX = %d  signed char의 최댓값 \n", SCHAR_MAX);
	printf(" UCHAR_MAX = %d  unsigned char의 최댓값 \n", UCHAR_MAX);


	puts("\n short형");

	printf(" SHRT_MIN  = %d short int 최솟값  \n", SHRT_MIN);
	printf(" SHRT_MAX  = %d short int 최댓값  \n", SHRT_MAX);
	printf(" USHRT_MAX = %d unsigned short int 최댓값  \n", USHRT_MAX);


	puts("\n int형 ");

	printf(" INT_MIN  = %d short int 최솟값  \n", INT_MIN);
	printf(" INT_MAX  = %d short int 최댓값  \n", INT_MAX);
	printf(" UINT_MAX = %u unsigned short int 최댓값  \n", UINT_MAX);

	puts("\n long형 ");

	printf(" LONG_MIN  = %d short long 최솟값  \n", LONG_MIN);
	printf(" LONG_MAX  = %d short long 최댓값  \n", LONG_MAX);
	printf(" ULONG_MAX = %u unsigned short long 최댓값  \n", ULONG_MAX);
}


/* 문자열 안의 문자를 16진수와 2진수로 출력합니다 */

void str_dump(const char* s) {
	do {
		printf("%c %0*X ", *s,(CHAR_BIT + 3) / 4, *s);
		for (int i = CHAR_BIT - 1; i >= 0; i--)
			putchar(((*s >> i) & 1U) ? '1' : '0');       // 접미사 U -> unsigned 타입
		putchar('\n');
	} while (*s++ != '\0');
}

void str_dump_() {
	limits_h();
	str_dump("STRING");
}