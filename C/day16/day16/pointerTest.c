#include<stdio.h>

void main() {
	int data = 10;
	int data2 = 20;
	int* pData = &data;
	pData = &data2;

	printf("%d\n", data);
	printf("%d\n", *pData);
	printf("%p\n", &data2);
	printf("%p\n", pData);
}