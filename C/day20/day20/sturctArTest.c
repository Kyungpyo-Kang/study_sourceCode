#include<stdio.h>
#pragma pack(push, 1)
#define L 3
typedef struct Car {
	char brand[30];
	int price;
	char color[30];
}tag_Car;


void main() {
	tag_Car cars[L] = { 0, };
	for (int i = 0; i < L; i++) {
		printf("[%d번째]\n", i + 1);
		printf("자동차 브랜드 : ");
		scanf_s("%s", cars[i].brand, sizeof(cars[i].brand));
		printf("자동차 가격 : ");
		scanf_s("%d", &cars[i].price);
		printf("자동차 색상 : ");
		scanf_s("%s", cars[i].color, sizeof(cars[i].color));
	}


	for (int i = 0; i < L; i++) {
		printf("[%d번째]\n", i + 1);
		printf("자동차 브랜드 : %s\n", cars[i].brand);
		printf("자동차 가격 : %d\n", cars[i].price);
		printf("자동차 색상 : %s\n", cars[i].color);
	}
}