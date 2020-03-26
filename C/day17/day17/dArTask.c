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
	printf("������ �Է����ּ��� : ");
	scanf_s("%d", &cnt);

	int* dArNum = malloc(sizeof(int)*cnt);

	for (int i = 0; i < cnt; i++) {
		printf("%d��° ���� : ", i + 1);
		scanf_s("%d", dArNum + i);
	}

	return dArNum;
}





void main() {
	//���� ���� �Է¹ް� �׸�ŭ �Ҵ��ϱ�
	//�Է¹��� ������ �������� �Ǵ� �������� ���� �� ��� ���
	//��������, ��������
	//1. ��������\n2.��������\n3.������


	char titleMsg[100] = "<������ ����� �������ּ���>\n";
	char choiceMsg[100] = "1.��������\n2.��������\n3.������\n";
	char errMsg[100] = "�ٽ� �Է����ּ���\n";
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





