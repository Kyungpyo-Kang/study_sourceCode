#include<stdio.h>
void main() {
	//���� �ΰ� �Է¹ޱ�
	//�ʱⰪ : 0, 0.0, " "
	int num1 = 0, num2 = 0;
	const char* n1Msg = "ù��° ���� : ";
	const char* n2Msg = "�ι�° ���� : ";
	int result = 0;
	printf("%s", n1Msg);
	scanf_s("%d",&num1);
	printf("%s", n2Msg);
	scanf_s("%d",&num2);
	result = num1 + num2;
	printf("num1 : %d\n", num1);
	printf("num2 : %d\n", num2);
	printf("%d+%d=%d\n", num1, num2, result);
}