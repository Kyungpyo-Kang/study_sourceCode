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
	char** dArName = 0;
	int* dArScore = 0;
	int cnt = 0;
	char temp[30] = "";
	

	printf("학생 수를 입력하세요>>");
	scanf_s("%d", &cnt);
	dArScore = (int*)malloc(sizeof(int)*cnt);
	dArName = (char**)malloc(sizeof(char*)*cnt);

	for (int i = 0; i < cnt; i++) {
		dArName[i] = (char*)malloc(sizeof(char) * 30);
		printf("이름 : ");
		scanf_s("%s", temp, sizeof(temp));
		for (int j = 0; j < 30; j++) {
			dArName[i][j] = temp[j];
		}
		
		
		printf("%s 학생 점수 : ", dArName[i]);
		scanf_s("%d", dArScore + i);
	}
	system("cls");

	for (int i = 10; i > 0; i--)
	{
		printf("%3d\t│", i * 10);
		for (int j = 0; j < cnt; j++) {
			if (dArScore[j] >= i * 10) {
				if (dArScore[j] == i * 10) {
					//뚜껑
					printf("┌─┐\t");
				}
				else {
					//막대
					printf("│ │\t");

				}
			}
			else {
				printf(" \t");
			}
			Sleep(100);
		}
		printf("\n");

	}
	printf("%3d\t└──────────────────────────\n", 0);
	printf("이름");
	for (int i = 0; i < cnt; i++) {
		printf("\t%s", dArName[i]);
	}
	printf("\n");

	for (int i = 0; i < cnt; i++) {
		free(dArName[i]);
	}
	free(dArName);
	free(dArScore);

}