#include <stdio.h>
#define L 5
//5���� ���޹޾� �ִ񰪰� �ּڰ� void�� �Լ�


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

	printf("5���� ���� �Է�\n");
	for (int i = 0; i < L; i++)
	{
		printf("%d��° : ", i + 1);
		scanf_s("%d", arNum + i);
	}



	findMaxMin(arNum, &minNum, &maxNum);
	printf("�ּڰ� : %d\n", minNum);
	printf("�ִ� : %d\n", maxNum);
	
}