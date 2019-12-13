// inflearn | C�� C++�� ���ÿ� ������� - �ε鳫���� C/C++
// ����°� ����

#include <stdio.h>

int main() {
	// int a; // int�� 32��Ʈ(4����Ʈ), ������ ��� �� ���δ�
	// ���� �̸�: ���ĺ� ��ҹ���, _, ����(ù ��° ����)
	

	/*
	5�� �ڷ��� - part 1. ������ ����, ������ �ڷ���

	float: 32��Ʈ(4����Ʈ), �Ǽ��� ��� �� ���δ� - �ε��Ҽ���
	double: 64��Ʈ(8����Ʈ), �Ǽ��� ��� �� ���δ� (�� ��Ȯ�ϰ� �Ǽ��� ��Ƴ���)

	�ε��Ҽ���(floating point) - �Ҽ����� ���ٴѴٰ� �ؼ� �ε��Ҽ���.. double�� �׳� �� ���� ���̶� double
	*/


	/*
	5�� �ڷ��� - part 2. ������, C/C++�� �ڷ��� ������

	�ڷ��� - ������, �Ǽ���

	������
		char (1����Ʈ) - ���ڸ� ��� �� ����
		short (2����Ʈ)
		long (4����Ʈ) -2147483648 ~ +2147483647  (2^32 -1 = 4294967295 ... 0 ~ +4294967295)
		long long (8����Ʈ)
		int (�ý��ۿ� ���� �ڵ� ����, ��ü�� long)

	�Ǽ���
		float (4����Ʈ)
		double (8����Ʈ)

	unsigned, signed
		unsigned int a; // ���̳ʽ��� ���� �ʴ� ��� (�� ó�� ��ȣ�� �����ϴ� ĭ���� ���ڸ� �����ϰڴ�)

	void: ���ϰ��� ���� �Լ��� �ڷ���

	bool: ��/������ �����ϴ� �ڷ���
	*/


	// sizeof(x): x�� ũ�⸦ �˷���
	// x: ��(int, float, ...)
	//    ���� �̸�
	printf("%d %d %d %d\n", sizeof(int), sizeof(char), sizeof(float), sizeof(double));

	int a; char b; float c; double d;
	printf("%d %d %d %d\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d));  // 4 1 4 8

	// ����ȯ: �ڷ����� �ٸ� �ڷ������� �ٲٴ� �۾�
	int math = 90, korean = 95, english = 96;
	int sum = math + korean + english;
	double avg = (double)sum / 3;
	printf("%f\n", avg); 


	/*
	8�� - char���� ASCII �ڵ�
	char: 1����Ʈ ������(int: 4����Ʈ)
	character: ���� (�ݰ����� - ABCabc123!@#$) (�ѱ�, �Ϻ���, ���� �� �������� ����)
	*/

	char word = 65;

	printf("%d\n", word); // 65
	printf("%c\n", word);  // A
	printf("%d\n", 'C');  // 67

	// ASCII: American Standard (����-����)
	char letter;
	printf("���� �Է�: ");
	scanf("%c", &letter);
	printf("����� �Է��� ���ڴ� %c�Դϴ�\n", letter);
	printf("����� �Է��� ������ ASCII ��ȣ�� %d�Դϴ�\n", letter);

	int number;
	printf("���� �Է�: ");
	scanf("%d", &number);
	printf("����� �Է��� ���ڴ� %d�Դϴ�\n", number);
	printf("����� �Է��� ������ ASCII ���ڴ� %c�Դϴ�\n", number);
}