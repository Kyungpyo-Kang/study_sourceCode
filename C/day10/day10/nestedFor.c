#include<stdio.h>
#define L 9
void main() {
	//������ 1��~9�ܱ��� ���
	//for�� �� ���� ���
	//������ �Ѱ��� ���
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