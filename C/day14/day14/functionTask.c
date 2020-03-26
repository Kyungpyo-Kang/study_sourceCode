#include<stdio.h>
#include<string.h>
//5개의 정수 중 최대값 최소값 구하기
int* temp;


int* getMaxMin(int arData[], int length) {
	int result[2] = { arData[0], arData[0] };
	
	for (int i = 1; i < length; i++) {
		if (result[1] < arData[i]) {
			result[1] = arData[i];
		} 
		if (result[0] > arData[i]) {
			result[0] = arData[i];
		}
	}
	return result;
}


/*


[고급]
정수를 한글로 바꿔주는 함수
5개의 정수를 오름차순으로 정렬하는 함수


*/
//	4자리 수
//	외부에서 문자열 배열의 주소값을 전달받는다.
void changeToHangle(int num, const char result[][3]) {
	//"영"~"구"까지 문자열 배열에 담는다.
	//외부에서 전달받은 정수 num의 각 자릿수 정수가 바로 hangle의 인덱스
	//번호로 활용된다.
	//1024
	char hangle[10][3] = { "영", "일", "이", "삼", "사", "오", "육", "칠", "팔", "구" };
	int idx = 0;
	//num이 0이라는 뜻은 모든 자릿수의 정수를 구했다는 뜻이다.
	//num이 0일 때 탈출!
	while (num != 0) {
		
//		result[idx] = hangle[num % 10];
		//1024%10 ==4
		//1024/10 == 102

		//1의 자릿수부터 구해지기 때문에 역으로 넣어주기 위해
		//3-idx를 해준다.

		strcpy_s(result[3-idx], sizeof(result[3-idx]), hangle[num % 10]);
		//작업 완료 시 1의 자리수를 떼어준다.
		num /= 10;
		//인덱스는 1 증가시켜준다.
		//3-idx : (3,2,1,0)
		idx++;
	}
}


//	5개의 정수를 오름차순으로 정렬하는 함수



void sortASC(int arNum[], int length) {
	//i번째 방의 값을 i+1부터 j번째 방에 있는 정수와 비교 후 
	//뒤의 값이 더 작으면 위치를 바꿔줘서 오름차순으로 정렬한다.

	for (int i = 0; i < length-1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (arNum[i] > arNum[j]) {
				//i번째 값을 덮어 씌우기 전에 temp에 담아놓고
				//j번째 방에 temp 값을 넣는다.
				//즉, 두 공간에 있는 값을 서로 바꾸어 주는 작업
				int temp = arNum[i];
				arNum[i] = arNum[j];
				arNum[j] = temp;
			}
		}
	}
	//3,4,5,2,1
	//1회전 : 1,4,5,2,3
	//2회전 : 1,2,5,4,3
	//3회전 : 1,2,3,4,5
}

void sortDESC(int arNum[], int length) {
	for (int i = 0; i < length-1; i++) {
		for (int j = i+1; j < length; j++) {
			if (arNum[i] < arNum[j]) {
				int temp = arNum[i];
				arNum[i] = arNum[j];
				arNum[j] = temp;
			}
		}
	}
}




void main() {

	int arData[5] = { 3,4,5,2,1 };
	int length = sizeof(arData) / sizeof(int);
	//sortASC(arData, length);
	sortDESC(arData, length);
	for (int i = 0; i < length; i++) {
		printf("%d ", arData[i]);
	}
	printf("\n");


	/*char result[4][3] = { "", };
	changeToHangle(1024, result);
	for (int i = 0; i < 4; i++) {
		printf("%s\n", result[i]);
	}*/
	/*for (int i = 0; i < 4; i++) {
		printf("%s\n", result[i]);
	}*/


/*	int arData[5] = {5,3,1,8,3};
	int length = sizeof(arData) / sizeof(int);
	printf("최댓값 : %d\n", *getMaxMin(arData, length));
	printf("최솟값 : %d\n", *getMaxMin(arData, length) +1);*/



}