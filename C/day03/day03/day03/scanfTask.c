#include<stdio.h>

void main() {
	//�� ������ �Է¹ް� ��� �������� ����ϱ�
	//�� : /
	//������ : % (�� : 10%3 == 1)
	int num1 = 0, num2 = 0, value = 0, mod = 0;
	/*const char* n1Msg = "ù��° ���� : ";
	const char* n2Msg = "�ι�° ���� : ";
	printf("%s", n1Msg);
	scanf_s("%d", &num1);
	printf("%s", n2Msg);
	scanf_s("%d", &num2);*/
	const char* numMsg = "���� �ΰ��� �Է��ϼ���.\n��)1,2\n>>>";
	printf("%s", numMsg);
	scanf_s("%d,%d", &num1, &num2);


	value = num1 / num2;
	mod = num1 % num2;
	printf("��\t: %d\n", value);
	printf("������\t: %d\n", mod);

}