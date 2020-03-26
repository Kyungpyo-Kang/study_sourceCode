#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>


void main() {
	//학생 수를 입력받고 그만큼 동적할당
	//학생 별 점수 입력
	//ㅂ한자를 누르면 x축과 y축을 이어서 그릴수 있다.
	//│★
	//│★ ★
	//└──────

	int* dArScore = 0;
	int cnt = 0;


	printf("학생 수를 입력하세요>>");
	scanf_s("%d", &cnt);
	dArScore = (int*)malloc(sizeof(int)*cnt);

	printf("점수를 입력하세요\n");
	for (int i = 0; i < cnt; i++) {
		printf("%d번째 학생 점수 : ", i + 1);
		scanf_s("%d", dArScore + i);
	}


	for (int i = 10; i > 0 ; i--)
	{
		printf("%3d\t│", i * 10);
		for (int j = 0; j < cnt; j++) {
			if (dArScore[j] >= i * 10) {
				printf("★\t");
			}
			else {
				printf(" \t");
			}
		}
		printf("\n");

	}
	printf("%3d\t└──────────────────────────\n",0);
	printf("점수");
	for (int i = 0; i < cnt; i++) {
		printf("\t%d", dArScore[i]);
	}
	printf("\n");



}