#include <stdio.h>  // include �ϳ��� �ؾ��ϴ°ǰ�?
#include <cmath>

int main() {
	int T, N, sum;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		sum = 0;
		for (int j = 1; j <= 10; j++) {
			scanf("%d", &N);
			sum += N;
		}
		// �ø�, ����, �ݿø�, ���� �Լ� ���� ���� ��ũ(https://blockdmask.tistory.com/112)
		printf("#%d %d\n", i, int(floor((sum / 10.0) + 0.5)));
		// printf("#%d %d\n", i, floor((sum/10.0)+0.5)); // �̷��� �ϸ� ���� Ʋ���� ������ ������?
	}
}