#include<stdio.h>
#pragma pack(push, 1)
typedef struct Car {
	char brand[30];
	int price;
	char color[30];
}tag_Car;

void main() {
	
	tag_Car cars[] = { { "Benz", 9000, "Black" },{ "BMW", 8000, "Blue" },{ "Bently", 35000, "White" } };
	int length = sizeof(cars) / sizeof(tag_Car);
	



}