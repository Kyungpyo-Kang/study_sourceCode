#include<stdio.h>
#define L 5


void main() {
	//5���� ������ �Է¹ް� ���� ���ϱ�
	//�迭 ���
	int arData[L] = { 0, };
	int result = 0;

	for (int i = 0; i < L; i++) {
		printf("���� %d : ", i + 1);
		scanf_s("%d", arData + i);
		result += arData[i];
	}
	printf("�Է��� ������ ���� : %d\n", result);
}