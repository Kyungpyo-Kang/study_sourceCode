#include<stdio.h>
#define L 9
void main() {
	//구구단 1단~9단까지 출력
	//for문 한 번만 출력
	//변수도 한개만 사용
	// 1,2,3,4, => i / 10
	/*for (int i = 0; i < L; i++) {
		printf("%d*%d=%d\n", i / 9 + 1, i % 9 + 1, ((i / 9) + 1)*(i % 9+1));
	}*/
	/*for (int i = 0; i < L; i++) {
		if (i % 10 == 0) {
			continue;
		}
		printf("%d*%d=%d\n", i / 10 + 1,i%10, ((i / 10) + 1)*(i % 10));
	}*/

	for (int i = 1; i < L+1; i++) {
		for (int j = 1; j < L+1; j++) {
			printf("%d*%d=%d\n", i, j, i*j);
		}
		printf("\n");
	}




}