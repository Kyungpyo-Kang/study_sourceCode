#include<stdio.h>
#define LENGTH 4		//현재 파일에서 4 대신에 LENGTH를 쓰겠다.		→	전처리 명령어
void main() {
	//변수
	int data1 = 10;
	//상수
	const int data2 = 4;
	// data2 = 100;		오류

	//int arData[data2] = { 1,3,4,5 };		배열은 메모리에 가장 먼저 할당되기 때문에 앞에서 상수 data2를 선언해도 오류가 난다.
	int arData[LENGTH] = { 1,3,4,5 };		//LENGTH가 전처리 명령어에 의해서 가장 먼저 메모리에 할당되었기 때문에 오류가 나지 않는다.



}