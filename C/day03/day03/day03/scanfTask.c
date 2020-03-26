#include<stdio.h>

void main() {
	//두 정수를 입력받고 몫과 나머지를 출력하기
	//몫 : /
	//나머지 : % (예 : 10%3 == 1)
	int num1 = 0, num2 = 0, value = 0, mod = 0;
	/*const char* n1Msg = "첫번째 정수 : ";
	const char* n2Msg = "두번째 정수 : ";
	printf("%s", n1Msg);
	scanf_s("%d", &num1);
	printf("%s", n2Msg);
	scanf_s("%d", &num2);*/
	const char* numMsg = "정수 두개를 입력하세요.\n예)1,2\n>>>";
	printf("%s", numMsg);
	scanf_s("%d,%d", &num1, &num2);


	value = num1 / num2;
	mod = num1 % num2;
	printf("몫\t: %d\n", value);
	printf("나머지\t: %d\n", mod);

}