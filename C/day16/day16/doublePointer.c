#include<stdio.h>

void function(int** PPData) {
	int data = 100;
	*PPData = &data;
}


void main() {
	int data = 10;
	int* PData = &data;
	function(&PData);
	printf("%d\n", *PData);
}