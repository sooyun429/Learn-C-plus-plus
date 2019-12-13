// inflearn | C와 C++을 동시에 배워보자 - 두들낙서의 C/C++
// 입출력과 변수

#include <stdio.h>

int main() {
	// int a; // int는 32비트(4바이트), 정수를 담는 데 쓰인다
	// 변수 이름: 알파벳 대소문자, _, 숫자(첫 번째 글자)
	

	/*
	5강 자료형 - part 1. 변수의 연산, 변수의 자료형

	float: 32비트(4바이트), 실수를 담는 데 쓰인다 - 부동소수점
	double: 64비트(8바이트), 실수를 담는 데 쓰인다 (더 정확하게 실수를 담아낸다)

	부동소수점(floating point) - 소수점이 떠다닌다고 해서 부동소수점.. double은 그냥 두 배의 길이라서 double
	*/


	/*
	5강 자료형 - part 2. 이진법, C/C++의 자료형 총정리

	자료형 - 정수형, 실수형

	정수형
		char (1바이트) - 문자를 담는 데 쓰임
		short (2바이트)
		long (4바이트) -2147483648 ~ +2147483647  (2^32 -1 = 4294967295 ... 0 ~ +4294967295)
		long long (8바이트)
		int (시스템에 따라서 자동 결정, 대체로 long)

	실수형
		float (4바이트)
		double (8바이트)

	unsigned, signed
		unsigned int a; // 마이너스를 쓰지 않는 경우 (맨 처음 부호를 저장하는 칸까지 숫자를 저장하겠다)

	void: 리턴값이 없는 함수의 자료형

	bool: 참/거짓을 저장하는 자료형
	*/


	// sizeof(x): x의 크기를 알려줌
	// x: 형(int, float, ...)
	//    변수 이름
	printf("%d %d %d %d\n", sizeof(int), sizeof(char), sizeof(float), sizeof(double));

	int a; char b; float c; double d;
	printf("%d %d %d %d\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d));  // 4 1 4 8

	// 형변환: 자료형을 다른 자료형으로 바꾸는 작업
	int math = 90, korean = 95, english = 96;
	int sum = math + korean + english;
	double avg = (double)sum / 3;
	printf("%f\n", avg); 


	/*
	8강 - char형과 ASCII 코드
	char: 1바이트 정수형(int: 4바이트)
	character: 문자 (반각문자 - ABCabc123!@#$) (한글, 일본어, 한자 등 전각문자 제외)
	*/

	char word = 65;

	printf("%d\n", word); // 65
	printf("%c\n", word);  // A
	printf("%d\n", 'C');  // 67

	// ASCII: American Standard (문자-숫자)
	char letter;
	printf("문자 입력: ");
	scanf("%c", &letter);
	printf("당신이 입력한 문자는 %c입니다\n", letter);
	printf("당신이 입력한 문자의 ASCII 번호는 %d입니다\n", letter);

	int number;
	printf("숫자 입력: ");
	scanf("%d", &number);
	printf("당신이 입력한 숫자는 %d입니다\n", number);
	printf("당신이 입력한 숫자의 ASCII 문자는 %c입니다\n", number);
}