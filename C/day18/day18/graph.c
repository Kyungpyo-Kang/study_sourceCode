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

	int* dArScore = 0;
	int cnt = 0;
	

	printf("�л� ���� �Է��ϼ���>>");
	scanf_s("%d", &cnt);
	dArScore = (int*)malloc(sizeof(int)*cnt);

	printf("������ �Է��ϼ���\n");
	for (int i = 0; i < cnt; i++) {
		printf("%d��° �л� ���� : ", i + 1);
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
	printf("����");
	for (int i = 0; i < cnt; i++) {
		printf("\t%d", dArScore[i]);
	}
	printf("\n");



}