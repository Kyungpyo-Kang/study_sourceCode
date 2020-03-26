#include<stdio.h>
void main() {
	int num = 10 & 11;
	int num2 = 10 | 11;
	int num3 = 10 ^ 11;
	int num4 = ~10;
	printf("%d\n", num);
	printf("%d\n", num2);
	printf("%d\n", num3);
	printf("%d\n", num4);
}