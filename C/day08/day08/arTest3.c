#include<stdio.h>
#define L 5
void main() {
	int arData[L] = { 0, };

	for (int i = 0; i < L; i++)
	{
		//printf("%d��° ���� : \n", i + 1);
		printf("���� %d : ", i + 1);
		scanf_s("%d", arData + i);
	}

	for (int i = 0; i < L; i++)
	{
		printf("%d ", arData[i]);
	}
	printf("\n");

	

}