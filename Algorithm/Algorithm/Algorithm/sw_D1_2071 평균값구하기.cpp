#include <stdio.h>  // include 하나씩 해야하는건가?
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
		// 올림, 내림, 반올림, 버림 함수 관련 참고 링크(https://blockdmask.tistory.com/112)
		printf("#%d %d\n", i, int(floor((sum / 10.0) + 0.5)));
		// printf("#%d %d\n", i, floor((sum/10.0)+0.5)); // 이렇게 하면 값이 틀리게 나오는 이유는?
	}
}