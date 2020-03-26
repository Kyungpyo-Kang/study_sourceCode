#include<stdio.h>

void main() {
	int data1 = 10;
	double data2 = 20.56;
	char data3 = 'A';


	void* arData[] = { &data1, &data2, &data3 };


	printf("%d\n", *(int*)arData[0]);


	/*int* PData1 = &data1;
	double* PData2 = &data2;
	char* PData3 = &data3*/;
}