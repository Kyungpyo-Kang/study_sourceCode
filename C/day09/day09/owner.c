#include<stdio.h>
#define L 3
void main() {
	//1�� 1ȣ 2ȣ 3ȣ

	//�� ����, ��� ����(�������)
	int arIncome[L] = { 0, };
	int sum = 0;
	double avg = 0.0;

	for (int i = 0; i < L; i++){
		printf("%dȣ ���� �Է�(���� : ����)\n", i + 1);
		scanf_s("%d", arIncome + i);
		sum += arIncome[i];
	}
	avg = (sum+0.0) / L;
	printf("1�� �� ���� : %d����\n", sum);
	printf("1�� ��� ���� : %.2f����\n", avg);


}