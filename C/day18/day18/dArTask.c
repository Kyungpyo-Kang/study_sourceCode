#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void sortASC(int arData[], int length);
void sortDESC(int arData[], int length);

void main() {
	//���� ���� �Է¹ް� �� ��ŭ �Ҵ��ϱ�
	//�Է¹��� ������ ��������(void �Լ�) �Ǵ� ��������(void �Լ�) ���� �� ��� ���
	//1.��������\n2.��������\n3.������
	int* dArNum = 0;
	int length = 0;
	int choice = 0;
	char* dot[] = { ".", "..", "..." };
	char* loading[] = { "����������", "����������", "����������", "����������", "����������", "����������", "����������", "����������", "����������" };

	while (1) {
		printf("[���� ���α׷�]\n");
		printf("���������\n�賻������\n�鳪����\n");
		scanf_s("%d", &choice);

		if (choice == 3) { break; }

		if (choice == 1 || choice == 2) {
			printf("�Է��Ͻ� �������� : ");
			scanf_s("%d", &length);

			dArNum = (int*)malloc(sizeof(int) * length);

			for (int i = 0; i < length; i++) {
				printf("%d��° ���� : ", i + 1);
				scanf_s("%d", dArNum + i);
			}

			//0 1 2 3 4 5 6 7 8 : 000 111 222
			for (int i = 0; i < 9; i++) {
				system("cls");
				printf("%s\n", loading[i]);
				printf("      ������%s\n", dot[i / 3]);
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
			//��� :
			//�� ������ 0.5�ʿ� �ϳ��� ��µȴ�.
			printf("��� : ");
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