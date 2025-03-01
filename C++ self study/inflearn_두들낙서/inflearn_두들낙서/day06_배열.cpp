// inflearn | C와 C++을 동시에 배워보자 - 두들낙서의 C/C++
// 배열

#include <stdio.h>

int main() {
	//array
	int arr[5] = { 3, 1, 4, 1, 5 }; // 배열의 개수가 정해져있으면 int arr[]처럼 숫자를 지정해주지 않아도 됨
	
	printf("%d\n", sizeof(arr)); // 전체 int 5개이므로 4*5 바이트

	// for (int i = 0; i <= 4; i++) {
	// for (int i = 0; i <= sizeof(arr)/sizeof(int)-1; i++) {
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) { // int는 4바이트(32bit)
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 다차원 배열(2차원 배열만)
	int double_arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	int double_arr2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // 이렇게 써줘도 가능함

	// 파스칼의 삼각형
	/*
	1
	1 1
	1 2 1
	1 3 3 1

	j == 0 || j == i -> 1
	i행 j열 = [[i-1][j-1]] + [[i-1][j]]
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