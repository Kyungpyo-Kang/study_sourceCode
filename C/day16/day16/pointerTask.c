#include<stdio.h>

void numSquere(int* PData) {
	*PData *= *PData;
}


//������ �Է¹ް� �Է¹��� ������ ������ �����ִ� void�� �Լ� �����ϱ�
//main() �Լ����� ������ �Է¹޴´�.
void main() {
	int data = 0;
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &data);
	printf("%d�� ���� : ", data);
	numSquere(&data);
	printf("%d\n", data);

}