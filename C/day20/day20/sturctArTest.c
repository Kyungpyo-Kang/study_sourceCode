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
		printf("[%d��°]\n", i + 1);
		printf("�ڵ��� �귣�� : ");
		scanf_s("%s", cars[i].brand, sizeof(cars[i].brand));
		printf("�ڵ��� ���� : ");
		scanf_s("%d", &cars[i].price);
		printf("�ڵ��� ���� : ");
		scanf_s("%s", cars[i].color, sizeof(cars[i].color));
	}


	for (int i = 0; i < L; i++) {
		printf("[%d��°]\n", i + 1);
		printf("�ڵ��� �귣�� : %s\n", cars[i].brand);
		printf("�ڵ��� ���� : %d\n", cars[i].price);
		printf("�ڵ��� ���� : %s\n", cars[i].color);
	}
}