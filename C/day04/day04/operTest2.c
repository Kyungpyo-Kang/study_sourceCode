#include<stdio.h>

void main() {
	//���� �� ���� �Է¹ޱ�.
	int num1 = 0;
	int num2 = 0;
	const char* numMsg = "���� �� ���� �Է����ּ���\n��)1,2\n>>>";
	int result = 0;
	printf("-9999�� �񱳴���� �ƴմϴ�.");
	printf("%s", numMsg);
	scanf_s("%d,%d", &num1, &num2);

	result = num1 > num2 ? num1 : num1 == num2? -9999 : num2;
	result == -9999? printf("�� ���� �����ϴ�.\n") : printf("ū �� : %d\n", result);


	

}