#include<stdio.h>

void main() {
	/*const char* numMsg = "���� �Ѱ��� �Է��ϼ���\n>>>";
	double num = 0.0;
	int sum = 0;*/
	//100~1���� ����ϱ�
	/*for (int i = 0; i < 100; i++)
	{
		printf("%d\n", 100-i);
	}*/
	//1~100���� �� ¦���� ����ϱ�
	/*for (int i = 0; i < 101; i++) {
		if (i % 2 == 0) {
			printf("%d\n", i);
		}
	}*/

	//1~n������ �� ����ϱ�
	/*printf("%s", numMsg);
	scanf_s("%d", &num);
	if(num > 1) {
		for (int i = 0; i < num; i++) {
		sum += i+1;
		}
		printf("�Է��� ���ڱ����� ���� : %d\n", sum);
	} else {
		printf("1���� ū ���� �Է�");
	}*/
	
	

	//�Է��� ���� �������� �Ǽ����� �Ǵ��ϰ� ����ϱ�.
	/*printf("%s", numMsg);
	scanf_s("%lf", &num);
	if ((int)num == num) {
		printf("�����Դϴ�.\n");
	}
	else if ((int)num < num) {
		printf("�Ǽ��Դϴ�.\n");
		}*/
	//A~F���� ����ϱ�
	/*for (int i = 0; i < 6; i++) {
		printf("%c\n", i+65);
	}*/

	//A~F���� �� C �����ϰ� ����ϱ�
	/*for (int i = 0; i < 6; i++) {
		if (i != 2) {
			printf("%c\n", i + 65);
		}
	}*/
	/*int temp = 0;
	for (int i = 0; i < 5; i++){
		temp = i;
		if (i > 1) {
			temp++;
		}
		printf("%c\n", temp + 65);
	}*/
	//A~F���� �� C�� �ҹ��ڷ� ����ϱ�
	/*for (int i = 0; i < 6; i++) {
		if (i == 2) {
			printf("%c\n", i + 97);
		}
		else {
			printf("%c\n", i + 65);
		}
	}*/
	/*for (int i = 0; i < 6; i++){
		printf("%c\n", i == 2 ? i + 97 : i + 65);
	}*/


	//aBcDerFg.....Z����ϱ�
	/*for (int i = 0; i < 26; i++)
	{
		if (i % 2 == 0) {
			printf("%c ", i + 97);
		}
		else if (i % 2 != 0) {
			printf("%c ", i + 65);
		}
	}*/

	/*for (int i = 0; i < 26; i++){
		printf("%c", i % 2 == 0 ? i + 97 : i + 65);
	}*/


	//012012012����ϱ�
	/*for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) {
			printf("0");
		} else if(i % 3 == 1) {
			printf("1");
		}
		else if (i % 3 == 2) {
			printf("2");
		}
	}*/
	/*for (int i = 0; i < 9; i++){
		printf("%d\n", i % 3);
	}*/


}