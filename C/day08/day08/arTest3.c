#include<stdio.h>
#define L 5
void main() {
	int arData[L] = { 0, };

	for (int i = 0; i < L; i++)
	{
		//printf("%d번째 정수 : \n", i + 1);
		printf("정수 %d : ", i + 1);
		scanf_s("%d", arData + i);
	}

	for (int i = 0; i < L; i++)
	{
		printf("%d ", arData[i]);
	}
	printf("\n");

	

}