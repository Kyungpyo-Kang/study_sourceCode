#include<stdio.h>
#define R 2
#define C 3
void main() {
	//1Ãþ 1È£ 2È£ 3È£
	//2Ãþ 1È£ 2È£ 3È£
	int arrData[2][3] = { 0, };
	int arTotal[R] = { 0, };
	double arAvg[R] = { 0, };
	int total = 0;
	double avg = 0.0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%dÃþ %dÈ£ ¿ù¼¼ ÀÔ·Â(´ÜÀ§ : ¸¸¿ø)\n", i+1, j+1);
			scanf_s("%d", arrData[i]+j);
			total += arrData[i][j];
			arTotal[i] += arrData[i][j];
		}
		arAvg[i] = (arTotal[i]+0.0) / C;
	}
	avg = (double)total / (R*C);
	printf("1Ãþ Æò±Õ ¿ù¼¼ : %.1f¸¸¿ø\n", arAvg[0]);
	printf("2Ãþ Æò±Õ ¿ù¼¼ : %.1f¸¸¿ø\n", arAvg[1]);
	printf("ÃÑ ¿ù¼¼ : %d¸¸¿ø\n", total);
	printf("ÀüÃ¼ Æò±Õ ¿ù¼¼ : %.1f¸¸¿ø\n", avg);






}