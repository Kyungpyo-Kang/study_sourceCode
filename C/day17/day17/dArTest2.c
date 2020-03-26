#include<stdio.h>
#include<stdlib.h>

void main() {
	//정수를 입력받고 그만큼 배열 할당하기
	int cnt = 0;
	int* dArNum = 0;

	printf("정수를 입력해주세요 : ");
	scanf_s("%d", &cnt);
	dArNum = (int*)malloc(sizeof(int)*cnt);
	


	for (int i = 0; i < cnt; i++) {
		printf("%d번째 정수 : ", i + 1);
		scanf_s("%d", dArNum+i);
	}
	printf("\n");

	for (int i = 0; i < cnt; i++) {
		printf("%d\n", dArNum[i]);
	}

	free(dArNum);

}

