#include<stdio.h>
#define R 2
#define C 3
void main() {
	//1�� 1ȣ 2ȣ 3ȣ
	//2�� 1ȣ 2ȣ 3ȣ
	int arrData[2][3] = { 0, };
	int arTotal[R] = { 0, };
	double arAvg[R] = { 0, };
	int total = 0;
	double avg = 0.0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d�� %dȣ ���� �Է�(���� : ����)\n", i+1, j+1);
			scanf_s("%d", arrData[i]+j);
			total += arrData[i][j];
			arTotal[i] += arrData[i][j];
		}
		arAvg[i] = (arTotal[i]+0.0) / C;
	}
	avg = (double)total / (R*C);
	printf("1�� ��� ���� : %.1f����\n", arAvg[0]);
	printf("2�� ��� ���� : %.1f����\n", arAvg[1]);
	printf("�� ���� : %d����\n", total);
	printf("��ü ��� ���� : %.1f����\n", avg);






}