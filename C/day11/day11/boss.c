#include<stdio.h>
#define ROW 3
#define COL 2
void main() {
	//������ (�Ϲ� Ű��)
	//������ (�Ϲ� Ű��)
	//ȫ���� (�Ϲ� Ű��)

	int arrIncome[ROW][COL] = { 0, };
	// char arBranchName[R][100] = {"������", "������", "ȫ����"};

	//const char* arStore[ROW] = { "������", "������", "ȫ����" };  �������� ����
	char arStore[ROW][100] = { "������", "������", "ȫ����" };
	char arType[COL][100] = { "�Ϲ���", "Ű����" };

	int arStoreTotal[ROW] = { 0, };
	double arStoreAvg[ROW] = { 0.0, };
	int arTypeTotal[COL] = { 0, };
	double arTypeAvg[COL] = { 0.0, };
	int check = 0;

	int total = 0;
	double avg = 0.0;

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			//������ �Ϲ��� ����� �Է�
			//������ Ű���� ����� �Է�
			printf("%s %s ����� �Է�(���� : ����)", arStore[i], arType[j]);
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
		printf("%s �� ����� : %d����\n", arStore[i], arStoreTotal[i]);
		printf("%s ��� �����:%.2f����\n", arStore[i], arStoreAvg[i]);
	}
	for (int i = 0; i < COL; i++) {
		printf("%s �� ����� : %d����\n", arType[i], arTypeTotal[i]);
		printf("%s ��� �����:%.2f����\n", arType[i], arTypeAvg[i]);
	}


	printf("����Ű �� ����� : %d����\n", total);
	printf("����Ű ��� ����� : %.2f����\n", avg);


	//�μ�Ƽ�� ����
	printf("<�μ�Ƽ�� ����>\n");
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
			//�� ���� ����� ��� ��հ� ��
			//��ü ��պ��� ���� ����� ���� ���
			if (arrIncome[i][j] > avg) {
				printf("%s %s\n", arStore[i], arType[j]);
				check == 1;
			}
		}
	}

	//���ڸ� ������ �����ϸ� 0 �Ǵ� 1�� ���´�.
	if (check != 1) {
		//���� for������ if���� �� ���� ���� �ʾҴٸ�
		printf("�μ�Ƽ�� ������ �����ϴ�.\n");
	}


	



}