#include<stdio.h>
#define L 3
void main() {
	//1층 1호 2호 3호

	//총 월세, 평균 월세(백원단위)
	int arIncome[L] = { 0, };
	int sum = 0;
	double avg = 0.0;

	for (int i = 0; i < L; i++){
		printf("%d호 월세 입력(단위 : 만원)\n", i + 1);
		scanf_s("%d", arIncome + i);
		sum += arIncome[i];
	}
	avg = (sum+0.0) / L;
	printf("1층 총 월세 : %d만원\n", sum);
	printf("1층 평균 월세 : %.2f만원\n", avg);


}