// inflearn | C�� C++�� ���ÿ� ������� - �ε鳫���� C/C++
// �迭

#include <stdio.h>

int main() {
	//array
	int arr[5] = { 3, 1, 4, 1, 5 }; // �迭�� ������ ������������ int arr[]ó�� ���ڸ� ���������� �ʾƵ� ��
	
	printf("%d\n", sizeof(arr)); // ��ü int 5���̹Ƿ� 4*5 ����Ʈ

	// for (int i = 0; i <= 4; i++) {
	// for (int i = 0; i <= sizeof(arr)/sizeof(int)-1; i++) {
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) { // int�� 4����Ʈ(32bit)
		printf("%d ", arr[i]);
	}
	printf("\n");

	// ������ �迭(2���� �迭��)
	int double_arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	int double_arr2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // �̷��� ���൵ ������

	// �Ľ�Į�� �ﰢ��
	/*
	1
	1 1
	1 2 1
	1 3 3 1

	j == 0 || j == i -> 1
	i�� j�� = [[i-1][j-1]] + [[i-1][j]]
	*/
	int p[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j==i) {
				p[i][j] = 1;
			}
			else {
				p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
			}
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}