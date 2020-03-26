#include<stdio.h>
#include<stdlib.h>


int cnt;

void arrageASC(int* arNum) {
	int temp = 0;
	for (int i = 0; i < cnt-1; i++)
	{
		for (int j = i+1; i < cnt; i++) {
			if (arNum[i] > arNum[j]) {
				temp = arNum[i];
				arNum[i] = arNum[j];
				arNum[j] = temp;
			}
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%d\n", arNum[i]);
	}


}
void arrangeDESC(int* arNum) {
	int temp = 0;
	for (int i = 0; i < cnt-1; i++)
	{
		for (int j = i + 1; i < cnt; i++) {
			if (arNum[i] < arNum[j]) {
				temp = arNum[i];
				arNum[i] = arNum[j];
				arNum[j] = temp;
			}
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%d\n", arNum[i]);
	}
}

int* getArray() {
	printf("정수를 입력해주세요 : ");
	scanf_s("%d", &cnt);

	int* dArNum = malloc(sizeof(int)*cnt);

	for (int i = 0; i < cnt; i++) {
		printf("%d번째 정수 : ", i + 1);
		scanf_s("%d", dArNum + i);
	}

	return dArNum;
}





void main() {
	//정수 개수 입력받고 그만큼 할당하기
	//입력받은 정수로 오름차순 또는 내림차순 선택 후 결과 출력
	//오름차순, 내림차순
	//1. 오름차순\n2.내림차순\n3.나가기


	char titleMsg[100] = "<정렬할 방법을 선택해주세요>\n";
	char choiceMsg[100] = "1.오름차순\n2.내림차순\n3.나가기\n";
	char errMsg[100] = "다시 입력해주세요\n";
	int choice;

	while (1) {
		printf("%s%s", titleMsg, choiceMsg);
		scanf_s("%d", &choice);
		if (choice == 3) {
			break;
		}

		switch (choice) {
			case 1:
				arrageASC(getArray());

				break;
			case 2:
				arrangeDESC(getArray());
				break;
		
			default:
				printf("%s", errMsg);
				break;
		}
	}

	
}





