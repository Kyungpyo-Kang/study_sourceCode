#include<stdio.h>
#define L 5


void main() {
	//5개의 정수를 입력받고 총합 구하기
	//배열 사용
	int arData[L] = { 0, };
	int result = 0;

	for (int i = 0; i < L; i++) {
		printf("정수 %d : ", i + 1);
		scanf_s("%d", arData + i);
		result += arData[i];
	}
	printf("입력한 정수의 합은 : %d\n", result);
}