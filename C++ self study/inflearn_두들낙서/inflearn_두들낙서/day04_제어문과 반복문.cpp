// inflearn | C�� C++�� ���ÿ� ������� - �ε鳫���� C/C++
// switch�� / goto�� / �ݺ���(while)

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
	printf("if��: ");
	if (choice == 1) printf("New game\n");
	else if (choice == 2) printf("Loading game\n");
	else if (choice == 3) printf("Setup\n");
	else if (choice == 4) printf("Credit\n");
	else {
		printf("Wrong number\n");
		goto makeChoice;
	}
	*/

	printf("switch��: ");
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

	// goto��
	printf("goto��\n");
	int i = 1;

	repeat:
	printf("%d\n", i);
	if (i < 10) {
		i++;
		goto repeat;
	}


	// �ݺ���(while)
	printf("while��\n");
	i = 1;
	while (i <= 10) {
		printf("%d\n", i);
		i++;
	}

	// do-while
	printf("do-while��\n");

	i = 15;
	do {  // do ���� ������ �ϴ� �����Ű�� while���� ������ ��������. (1���� ������ �����)
		printf("%d\n", i);
		i++;
	} while (i <= 10);

	printf("###\n");
	i = 1;
	do {  // do ���� ������ �ϴ� �����Ű�� while���� ������ ��������. (1���� ������ �����)
		printf("%d\n", i);
		i++;
	} while (i <= 10);


	// �ݺ� (�Ʒ��� ���� scanf�� ������ 1���� �����غ����ϴ� ��� do-while���� ����)
	int n;
	do {
		printf("���� 0�� �Է����ּ���!!\n");
		scanf("%d", &n);
	} while (n != 0);

	printf("���� 0�� �Է��ϼ̱���!\n");
	
}