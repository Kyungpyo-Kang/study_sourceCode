#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void sortASC(int arData[], int length);
void sortDESC(int arData[], int length);

void main() {
	//정수 개수 입력받고 그 만큼 할당하기
	//입력받은 정수로 오름차순(void 함수) 또는 내림차순(void 함수) 선택 후 결과 출력
	//1.오름차순\n2.내림차순\n3.나가기
	int* dArNum = 0;
	int length = 0;
	int choice = 0;
	char* dot[] = { ".", "..", "..." };
	char* loading[] = { "■□□□□□□□□", "■■□□□□□□□", "■■■□□□□□□", "■■■■□□□□□", "■■■■■□□□□", "■■■■■■□□□", "■■■■■■■□□", "■■■■■■■■□", "■■■■■■■■■" };

	while (1) {
		printf("[정렬 프로그램]\n");
		printf("①오름차순\n②내림차순\n③나가기\n");
		scanf_s("%d", &choice);

		if (choice == 3) { break; }

		if (choice == 1 || choice == 2) {
			printf("입력하실 정수개수 : ");
			scanf_s("%d", &length);

			dArNum = (int*)malloc(sizeof(int) * length);

			for (int i = 0; i < length; i++) {
				printf("%d번째 정수 : ", i + 1);
				scanf_s("%d", dArNum + i);
			}

			//0 1 2 3 4 5 6 7 8 : 000 111 222
			for (int i = 0; i < 9; i++) {
				system("cls");
				printf("%s\n", loading[i]);
				printf("      정렬중%s\n", dot[i / 3]);
				Sleep(300);
			}

			switch (choice) {
			case 1:
				sortASC(dArNum, length);
				break;
			case 2:
				sortDESC(dArNum, length);
				break;
			}
			//결과 :
			//각 정수는 0.5초에 하나씩 출력된다.
			printf("결과 : ");
			for (int i = 0; i < length; i++) {
				Sleep(500);
				printf("%d ", dArNum[i]);
			}
			printf("\n");
		}
	}
	free(dArNum);
}

void sortASC(int arData[], int length) {
	int temp = 0;

	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (arData[i] > arData[j]) {
				temp = arData[i];
				arData[i] = arData[j];
				arData[j] = temp;
			}
		}
	}
}

void sortDESC(int arData[], int length) {
	int temp = 0;

	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (arData[i] < arData[j]) {
				temp = arData[i];
				arData[i] = arData[j];
				arData[j] = temp;
			}
		}
	}
}