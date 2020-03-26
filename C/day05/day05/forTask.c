#include<stdio.h>

void main() {
	/*const char* numMsg = "정수 한개를 입력하세요\n>>>";
	double num = 0.0;
	int sum = 0;*/
	//100~1까지 출력하기
	/*for (int i = 0; i < 100; i++)
	{
		printf("%d\n", 100-i);
	}*/
	//1~100까지 중 짝수만 출력하기
	/*for (int i = 0; i < 101; i++) {
		if (i % 2 == 0) {
			printf("%d\n", i);
		}
	}*/

	//1~n까지의 합 출력하기
	/*printf("%s", numMsg);
	scanf_s("%d", &num);
	if(num > 1) {
		for (int i = 0; i < num; i++) {
		sum += i+1;
		}
		printf("입력한 숫자까지의 합은 : %d\n", sum);
	} else {
		printf("1보다 큰 수를 입력");
	}*/
	
	

	//입력한 값이 정수인지 실수인지 판단하고 출력하기.
	/*printf("%s", numMsg);
	scanf_s("%lf", &num);
	if ((int)num == num) {
		printf("정수입니다.\n");
	}
	else if ((int)num < num) {
		printf("실수입니다.\n");
		}*/
	//A~F까지 출력하기
	/*for (int i = 0; i < 6; i++) {
		printf("%c\n", i+65);
	}*/

	//A~F까지 중 C 제외하고 출력하기
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
	//A~F까지 중 C만 소문자로 출력하기
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


	//aBcDerFg.....Z출력하기
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


	//012012012출력하기
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