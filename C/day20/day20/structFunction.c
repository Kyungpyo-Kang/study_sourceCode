#include<stdio.h>
typedef struct Virus {
	char name[30];
	double death_rate;
	int 감염자_cnt;
}tag_Virus;

void init(tag_Virus* Pv) {
	printf("바이러스 명칭: ");
	scanf_s("%s", Pv->name, sizeof(Pv->name));
	printf("바이러스 치사율 : ");
	scanf_s("%lf", &Pv->death_rate);
	printf("바이러스 감염자 수 : ");
	scanf_s("%d", &Pv->감염자_cnt);
}

void main() {
	tag_Virus corona19 = { 0, };
	init(&corona19);
	printf("바이러스 이름 : %s\n", corona19.name);




}