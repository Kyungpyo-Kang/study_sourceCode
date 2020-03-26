#include<stdio.h>

/*
	[초급]
	1~10까지 printf()로 출력하는 함수
	1~10까지의 합을 구해주는 함수
	1~n까지의 합을 구해주는 함수

	[중급]
	홀수를 짝수로, 짝수를 홀수로 바꿔주는 함수
	소문자를 대문자로 바꾸고 printf()로 출력하는 함수
	5개의 정수를 입력받고 최솟값과 최댓값을 구해주는 함수
	
	[고급]
	정수를 한글로 바꿔주는 함수
	5개의 정수를 오름차순으로 정렬하는 함수

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
	printf("정수를 입력해주세요 : ");
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
		printf("0이상의 수만 입력 가능합니다.");
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
		printf("a-z 사이의 소문자를 입력해주세요!\n");
	}
}


void findMaxMin() {
	int arNum[5] = { 0, };
	int resultNum[5] = { 0, };
	int min = 0;
	printf("5개의 정수를 입력해주세요\n");
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