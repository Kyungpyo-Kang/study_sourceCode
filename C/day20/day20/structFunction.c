#include<stdio.h>
typedef struct Virus {
	char name[30];
	double death_rate;
	int ������_cnt;
}tag_Virus;

void init(tag_Virus* Pv) {
	printf("���̷��� ��Ī: ");
	scanf_s("%s", Pv->name, sizeof(Pv->name));
	printf("���̷��� ġ���� : ");
	scanf_s("%lf", &Pv->death_rate);
	printf("���̷��� ������ �� : ");
	scanf_s("%d", &Pv->������_cnt);
}

void main() {
	tag_Virus corona19 = { 0, };
	init(&corona19);
	printf("���̷��� �̸� : %s\n", corona19.name);




}