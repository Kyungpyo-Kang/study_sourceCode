#include<stdio.h>

/*
	[�ʱ�]
	1~10���� printf()�� ����ϴ� �Լ�
	1~10������ ���� �����ִ� �Լ�
	1~n������ ���� �����ִ� �Լ�

	[�߱�]
	Ȧ���� ¦����, ¦���� Ȧ���� �ٲ��ִ� �Լ�
	�ҹ��ڸ� �빮�ڷ� �ٲٰ� printf()�� ����ϴ� �Լ�
	5���� ������ �Է¹ް� �ּڰ��� �ִ��� �����ִ� �Լ�
	
	[���]
	������ �ѱ۷� �ٲ��ִ� �Լ�
	5���� ������ ������������ �����ϴ� �Լ�

*/

void printNum() {
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", i + 1);
	}
	printf("\n");
}

int sumtoTen() {
	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += i + 1;
	}
	return result;
}

int sumNum() {
	int num = 0;
	int result = 0;
	printf("������ �Է����ּ��� : ");
	scanf_s("%d", &num);
	
	for (int i = 0; i < num; i++)
	{
		result += i + 1;
	}
	return result;
}


int cngOddEven(int num) {
	int result = 0;
	if (num < 0) {
		printf("0�̻��� ���� �Է� �����մϴ�.");
	}
	else
	{
		result = num + 1;
	}
	
	return result;
}


void changeLetter(char letter) {
	if ((char)letter >= 97 && (char) letter <123) {
		printf("%c\n", (char)letter - 32);
	}
	else
	{
		printf("a-z ������ �ҹ��ڸ� �Է����ּ���!\n");
	}
}


void findMaxMin() {
	int arNum[5] = { 0, };
	int resultNum[5] = { 0, };
	int min = 0;
	printf("5���� ������ �Է����ּ���\n");
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", arNum+i);
	}
	
	for (int i = 0; i < 5; i++) {
		if(arNum[0] <)
	}


	for (int i = 0; i < 5; i++) {
		printf("%d", resultNum[i]);
	}


}



void main() {
	/*printNum();
	changeLetter('z');*/
	findMaxMin();


}