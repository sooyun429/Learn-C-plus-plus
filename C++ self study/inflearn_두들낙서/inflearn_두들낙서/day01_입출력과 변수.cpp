// inflearn | C와 C++을 동시에 배워보자 - 두들낙서의 C/C++

#include <stdio.h>

int main() {
	printf("Hello, World!\n");

	printf("%d + %d = %d\n", 2, 3, 5);
	
	printf("%f\n", 3.14);  // 실수 출력값: 3.140000
	printf("%.2f\n", 3.141592); // 3.14
	printf("%.2f\n", 3.146592);  // 3.15 반올림

	// %g: 실수 출력(지수 형태로도 출력)
	printf("%g\n", 3.141592); // 3.14159
	printf("%.3g\n", 8238479285.12479235); // 8.24e+09

	// %c: 문자 출력(알파벳, 숫자, 몇몇 기호, \n) - 한글, 한자, 유니코드 x
	printf("%c %c %c\n", 97, 'b', 'c'); // a b c 로 출력됨 ascii code값

	// %s: 문자열 출력 - 한글 입력 가능
	printf("%s\n", "안녕하세요");
	printf("%s", "안녕하세요\n"); // 위와 동일한 값
}