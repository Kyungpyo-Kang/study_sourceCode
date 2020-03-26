#include<stdio.h>
#include<stdlib.h>
/*
	�л� ����ü ����(typedef)
	*���
	�л� �̸�, ����, ��, ��, �� ����
	�л� ���� �Է��� �Լ��� ����(void��)
	�� �л� ���� �Է¹޴´�.
	���� �迭�� �л� ����ü �迭 ���� �� �л� �� ����, ��� ���
*/

//����� ��Ģ�� �ο�
char* arSub[3] = { "����","����","����" };

typedef struct Student {
	char name[30];
	int age;
	//3ĭ ���� �迭
	int arScore[3];
}tag_Student;

//����ü �ּҸ� ���޹޾Ƽ� ���� �����Ͽ� �ʱ�ȭ ���ش�.
void inputInfo(tag_Student* member) {
	
	printf("�л� �̸� :");
	//��� ������ ������ �� 2�� ������ ������ ->(ȭ��ǥ ������)�� ����Ѵ�.
	scanf_s("%s", member->name, sizeof(member->name));
	printf("�л� ���� :");
	scanf_s("%d", &member->age);
	//������ 3���̹Ƿ� 3�� �ݺ��Ѵ�.
	for (int i = 0; i < 3; i++) {
		printf("%s ����", arSub[i]);
		scanf_s("%d", member->arScore + i);
	}
}



void main() {
	int cnt = 0;
	int total = 0;
	double avg = 0.0;
	printf("�л� �� : ");
	scanf_s("%d", &cnt);
	//�����Ҵ�
	tag_Student* arStudent = (tag_Student*)malloc(sizeof(tag_Student)*cnt);

	//�л� ����ŭ �ݺ��Ͽ� �� ����ü�� �ּҰ��� inputInfo�Լ��� �����Ѵ�.
	for (int i = 0; i < cnt; i++) {
		inputInfo(arStudent+i);
	}
	for (int i = 0; i < cnt; i++) {
		//���� �л��� ���� �ʱ�ȭ
		total = 0;
		//[], .�ι� �����ϹǷ� ������ ����� -> �����ڷ� ������ �� �ִ�.
		printf("%s �л�", (arStudent+i)->name);
		for (int j = 0; j < 3; j++) {
			printf("%s : %d��", arSub[j], (arStudent + i)->arScore[j]);
			total += (arStudent + i)->arScore[j];
		}
		avg = (double)total / 3;
		printf("���� : %d��", total);
		printf("��� : %2lf��", avg);
	}
	

}




