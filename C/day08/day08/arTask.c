#include<stdio.h>
#define L 5

void main() {
	//1~10까지 중 짝수만 배열에 넣고 출력하기

	int arData[L] = { 0, };

	for (int i = 0; i < L; i++) {
		arData[i] = (i + 1) * 2;
	}
	
	/*printf("%p\n", arData);
	printf("%p\n", &arData[0]);
	printf("%p\n", arData + 1);
	printf("%d\n", *(arData + 1));*/

	//arData에 담겨있는 값 포인터 연산으로 출력하기
	//대괄호는 사용하지 않는다.
	for (int i = 0; i < L; i++) {
		printf("%d ", *(arData + i));
	}
	printf("\n");



}








