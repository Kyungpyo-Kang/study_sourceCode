#include<stdio.h>
#define ROW 3
#define COL 2
void main() {
	//강남점 (일반 키즈)
	//신촌점 (일반 키즈)
	//홍대점 (일반 키즈)

	int arrIncome[ROW][COL] = { 0, };
	// char arBranchName[R][100] = {"강남점", "신촌점", "홍대점"};

	//const char* arStore[ROW] = { "강남점", "신촌점", "홍대점" };  유지보수 불편
	char arStore[ROW][100] = { "강남점", "신촌점", "홍대점" };
	char arType[COL][100] = { "일반점", "키즈점" };

	int arStoreTotal[ROW] = { 0, };
	double arStoreAvg[ROW] = { 0.0, };
	int arTypeTotal[COL] = { 0, };
	double arTypeAvg[COL] = { 0.0, };
	int check = 0;

	int total = 0;
	double avg = 0.0;

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			//강남점 일반점 매출액 입력
			//강남점 키즈점 매출액 입력
			printf("%s %s 매출액 입력(단위 : 만원)", arStore[i], arType[j]);
			scanf_s("%d", arrIncome[i]+j);
			arStoreTotal[i] += arrIncome[i][j];
			arTypeTotal[j] += arrIncome[i][j];
			total += arrIncome[i][j];
		}
		arStoreAvg[i] = (arStoreTotal[i]+0.0) / COL;
	}

	for (int i = 0; i < COL; i++) {
		arTypeAvg[i] = (arTypeTotal[i] + 0.0) / ROW;
	}

	avg = (total+0.0) / (COL*ROW);

	for (int i = 0; i < ROW; i++) {
		printf("%s 총 매출액 : %d만원\n", arStore[i], arStoreTotal[i]);
		printf("%s 평균 매출액:%.2f만원\n", arStore[i], arStoreAvg[i]);
	}
	for (int i = 0; i < COL; i++) {
		printf("%s 총 매출액 : %d만원\n", arType[i], arTypeTotal[i]);
		printf("%s 평균 매출액:%.2f만원\n", arType[i], arTypeAvg[i]);
	}


	printf("나이키 총 매출액 : %d만원\n", total);
	printf("나이키 평균 매출액 : %.2f만원\n", avg);


	//인센티브 매장
	printf("<인센티브 매장>\n");
	/*for (int i = 0; i < ROW; i++) {
		if (arStoreAvg[i] > avg) {
			printf("%d. %s\n", i + 1, arStore[i]);
		}
		for (int j = 1; j < ROW+1; j++)
		{
			if (arStoreAvg[i] == arStoreAvg[j]) {
				check = 1;
				continue;
			}
		}
	}*/

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//각 매장 매출액 모두 평균과 비교
			//전체 평균보다 높은 매출액 매장 출력
			if (arrIncome[i][j] > avg) {
				printf("%s %s\n", arStore[i], arType[j]);
				check == 1;
			}
		}
	}

	//문자를 정수로 변경하면 0 또는 1이 나온다.
	if (check != 1) {
		//위의 for문에서 if문에 한 번도 들어가지 않았다면
		printf("인센티브 매장이 없습니다.\n");
	}


	



}