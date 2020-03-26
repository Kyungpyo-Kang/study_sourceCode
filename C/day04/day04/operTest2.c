#include<stdio.h>

void main() {
	//정수 두 개를 입력받기.
	int num1 = 0;
	int num2 = 0;
	const char* numMsg = "정수 두 개를 입력해주세요\n예)1,2\n>>>";
	int result = 0;
	printf("-9999는 비교대상이 아닙니다.");
	printf("%s", numMsg);
	scanf_s("%d,%d", &num1, &num2);

	result = num1 > num2 ? num1 : num1 == num2? -9999 : num2;
	result == -9999? printf("두 수가 같습니다.\n") : printf("큰 값 : %d\n", result);


	

}