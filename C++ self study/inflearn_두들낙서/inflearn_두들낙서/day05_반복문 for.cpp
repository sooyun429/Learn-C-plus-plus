// inflearn | C와 C++을 동시에 배워보자 - 두들낙서의 C/C++
// for문

// 일정하게 증가/감소되는 변수가 필요할 때
// 배열의 모든 원소에 순차적으로 접근하고 싶을 때
// 특정 횟수만큼 작업을 반복하고 싶을 때

// break/continue
// 중첩for문

// 연산자: + - / * % += -= ++ -- && || !
// 제어문: if() switch()
// 반복문: while() for()

#include <stdio.h>

int main() {
	// 1, 2, 4, 8, 16, 32...

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i *= 2) { // 함수 또는 괄호 안에서 선언된 변수는 내에서만 사용 가능
		printf("%d\n", i);
	}

	// 그렇지 않다면 전역변수로 선언한 후 사용할 수도 있음
	// 그렇게 되면 for문 사용시 첫 부분을 비워두면 된다

	int i;
	scanf("%d", &i);

	for (; i <= 10; i++) { // 조건 부분(두 번째 공간) 을 true로 적거나 비워두면 true로 인식하고 무한반복됨
		printf("%d\n", i);
	}

	// 두 개 이상의 변수 선언도 가능
	// 2^0=1 / 2^1 = 2 / 2^2 = 4 / ...

	scanf("%d", &n);
	for (int i = 0, t = 1; i <= n; i++, t *= 2) {
		printf("2^%d = %d\n", i, t);
	}

	// sum의 경우도 아래처럼 사용 가능 (중괄호를 아예 사용 안할 수도 있다)
	int j, sum; // for문 밖에서 sum을 printf 로 사용하므로 전역변수로 선언해줘야 쓸 수 있음
	// sum만 선언하고 for (int j=1, sum=0.. 이런식으로 사용하면 에러가 난다.
	for (j = 1, sum = 0; j <= n; sum += j, j++);
	printf("%d\n", sum);

	// 중첩for문
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ", 2 * j + 1);
		}
		printf("\n");
	}
}