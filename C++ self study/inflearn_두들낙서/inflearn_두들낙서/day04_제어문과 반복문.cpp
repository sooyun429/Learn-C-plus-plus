// inflearn | C와 C++을 동시에 배워보자 - 두들낙서의 C/C++
// switch문 / goto문 / 반복문(while)

#include <stdio.h>

int main() {
	int choice;

	makeChoice:

	printf("New game: 1\n");
	printf("Loading game: 2\n");
	printf("Setup: 3\n");
	printf("Credit: 4\n");

	scanf("%d", &choice);

	/*
	printf("if문: ");
	if (choice == 1) printf("New game\n");
	else if (choice == 2) printf("Loading game\n");
	else if (choice == 3) printf("Setup\n");
	else if (choice == 4) printf("Credit\n");
	else {
		printf("Wrong number\n");
		goto makeChoice;
	}
	*/

	printf("switch문: ");
	switch (choice) {
	case 1:
		printf("New game\n");
		break;
	case 2:
		printf("Loading game\n");
		break;
	case 3:
		printf("Setup\n");
		break;
	case 4:
		printf("Credit\n");
		break;
	default:
		printf("Wrong number\n");
		goto makeChoice;
		break;
	}

	// goto문
	printf("goto문\n");
	int i = 1;

	repeat:
	printf("%d\n", i);
	if (i < 10) {
		i++;
		goto repeat;
	}


	// 반복문(while)
	printf("while문\n");
	i = 1;
	while (i <= 10) {
		printf("%d\n", i);
		i++;
	}

	// do-while
	printf("do-while문\n");

	i = 15;
	do {  // do 안의 내용을 일단 실행시키고 while문의 조건을 따져본다. (1번은 무조건 실행됨)
		printf("%d\n", i);
		i++;
	} while (i <= 10);

	printf("###\n");
	i = 1;
	do {  // do 안의 내용을 일단 실행시키고 while문의 조건을 따져본다. (1번은 무조건 실행됨)
		printf("%d\n", i);
		i++;
	} while (i <= 10);


	// 반복 (아래와 같이 scanf를 무조건 1번은 시작해봐야하는 경우 do-while문을 쓴다)
	int n;
	do {
		printf("제발 0을 입력해주세요!!\n");
		scanf("%d", &n);
	} while (n != 0);

	printf("드디어 0을 입력하셨군요!\n");
	
}