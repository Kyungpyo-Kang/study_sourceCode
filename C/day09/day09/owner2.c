#include<stdio.h>
#define L 3
#include<string.h>
void main() {
	//나이키
	//강남점 , 홍대점, 이태원점

	//입력 예) 강남점 매출액 입력(단위 : 만원)
	//나이키 총 매출액과 평균 매출액(천원단위) 출력
	//평균 매출액보다 높은 매장은 인센티브 매장으로 출력
	//출력 예)
	//인센티브 매장
	//홍대점
	//이태원점

	//나이키 총 매출액
	int total = 0;
	//나이키 평균 매출액
	double avg = 0;

	//문자열 배열(지점명)
	const char* arStore[L+1] = { "강남점", "홍대점", "이태원점" };
	//정수 배열(매출액)
	int arIncome[L] = { 0, };
	//Flag
	//int는 4byte이다. 메모리를 절약하기 위해서
	//문자로 선언한다.
	char check = '0';

	//지점 개수만큼 반복
	for (int i = 0; i < L; i++) {
		//각 지점명을 순서대로 출력
		printf("%s 매출액 입력(단위 : 만원)\n", arStore[i]);
		//입력받은 매출액을 순서대로 arIncome에 저장
		scanf_s("%d", arIncome + i);
		//입력받은 매출액을 total에 누적
		total += arIncome[i];
	}
	//누적된 총 매출액을 지점 개수로 나누어 평균 추출
	avg = (total+0.0) / L;

	printf("총 매출액 : %d만원\n평균 매출액 : %.1f만원\n", total, avg);

	/*평균보다 높은 매출액 매장 출력*/
	printf("<인센티브 매장>\n");
	for (int i = 0; i < L; i++){
		//모든 매장의 매출액을 평균과 비교
		if (arIncome[i] > avg) {
			//인센티브 매장은 이 영역으로 들어옴
			printf("%s(%d만원)\n", arStore[i], arIncome[i]);
			//인센티브를 받을 매장이 한 개라도 있다면
			//check를 '1'로 변경
			check = '1';
			}
		}
	//check에 -48을 해주면 정수 0(거짓) 또는 1(참)로 바뀐다.
	//위의 for문에서 if문에 한 번도 들어가지 않았다면
	//들어가서 "없습니다."를 출력한다.
	if (!(check-48)) {
		//'0' : 48 - 48 == 0
		//'1' : 49 - 48 == 1
		printf("인센티브 매장이 없습니다.\n");
	}

		
	









}