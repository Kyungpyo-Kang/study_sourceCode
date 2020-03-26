#include <stdio.h>
#define L 5
//5개의 전달받아 최댓값과 최솟값 void형 함수


void findMaxMin(int arNum[], int* PMinNum, int* PMaxNum) {

	*PMaxNum = arNum[0];
	*PMinNum = arNum[0];

	for (int i = 1; i < L; i++) {
		if (*PMinNum > arNum[i]) {
			*PMinNum = arNum[i];
		}
		if (*PMaxNum < arNum[i]) {
			*PMaxNum = arNum[i];
		}
	}


}


void main() {
	int arNum[L] = { 0, };
	int minNum = 0;
	int maxNum = 0;

	printf("5개의 정수 입력\n");
	for (int i = 0; i < L; i++)
	{
		printf("%d번째 : ", i + 1);
		scanf_s("%d", arNum + i);
	}



	findMaxMin(arNum, &minNum, &maxNum);
	printf("최솟값 : %d\n", minNum);
	printf("최댓값 : %d\n", maxNum);
	
}