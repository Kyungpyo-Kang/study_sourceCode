#include<stdio.h>
#include<string.h>
void main() {
	char nation[6] = "korea";
	//scanf("���Ĺ���", �迭��) : �迭�� ũ�⺸�� �Է¹��� ���� Ŀ�� 
	//							  �� ���Եȴ�. ������ �ս�!
	//scanf_s("%s", �迭��, sizeof(�迭��))
	//�迭�� ũ�⺸�� �Է¹��� ���� ũ��
	//�ƹ��͵� ���� �ʴ´�. ������ �ս� ����!

	//printf("���� : ");
	//scanf_s("%s", nation, sizeof(nation));

	//strcpy_s(nation, sizeof(nation), "china");


	//strcmp("��1", "��2");
	//0 : �� ���ڿ��� ���� ��
	printf("%d\n", strlen(nation));

	//��1�� ù ���ڰ� ��2�� ù ���ں��� Ŭ ��
	printf("%d\n",strcmp(nation, "china"));

	//0 : �� ���ڿ��� ���� ��
	printf("%d\n", strcmp(nation, "korea"));

	//�� 1�� ù ���ڰ� ��2�� ù ���ں��� ���� ��
	printf("%d\n", strcmp(nation, "rome"));


	


	printf("%s\n", nation);
}