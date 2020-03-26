#include<stdio.h>

void numSquere(int* PData) {
	*PData *= *PData;
}


//정수를 입력받고 입력받은 정수의 제곱을 구해주는 void형 함수 선언하기
//main() 함수에서 정수를 입력받는다.
void main() {
	int data = 0;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &data);
	printf("%d의 제곱 : ", data);
	numSquere(&data);
	printf("%d\n", data);

}