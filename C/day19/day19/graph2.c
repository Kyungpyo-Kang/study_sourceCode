#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>


void main() {
	//�л� ���� �Է¹ް� �׸�ŭ �����Ҵ�
	//�л� �� ���� �Է�
	//�����ڸ� ������ x��� y���� �̾ �׸��� �ִ�.
	//����
	//���� ��
	//��������������
	char** dArName = 0;
	int* dArScore = 0;
	int cnt = 0;
	char temp[30] = "";
	

	printf("�л� ���� �Է��ϼ���>>");
	scanf_s("%d", &cnt);
	dArScore = (int*)malloc(sizeof(int)*cnt);
	dArName = (char**)malloc(sizeof(char*)*cnt);

	for (int i = 0; i < cnt; i++) {
		dArName[i] = (char*)malloc(sizeof(char) * 30);
		printf("�̸� : ");
		scanf_s("%s", temp, sizeof(temp));
		for (int j = 0; j < 30; j++) {
			dArName[i][j] = temp[j];
		}
		
		
		printf("%s �л� ���� : ", dArName[i]);
		scanf_s("%d", dArScore + i);
	}
	system("cls");

	for (int i = 10; i > 0; i--)
	{
		printf("%3d\t��", i * 10);
		for (int j = 0; j < cnt; j++) {
			if (dArScore[j] >= i * 10) {
				if (dArScore[j] == i * 10) {
					//�Ѳ�
					printf("������\t");
				}
				else {
					//����
					printf("�� ��\t");

				}
			}
			else {
				printf(" \t");
			}
			Sleep(100);
		}
		printf("\n");

	}
	printf("%3d\t������������������������������������������������������\n", 0);
	printf("�̸�");
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