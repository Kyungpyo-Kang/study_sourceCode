#include<stdio.h>
#define L 3
void main() {
	int arData[L] = { 10, 20, 30 };
	
	int(*arPData)[L] = &arData;
	for (int i = 0; i < L; i++) {
		printf("%d\n", *(*arPData+i));
	}
	
	
	
	/*int* PArData[L] = { 0, };

	for (int i = 0; i < L; i++) {
		PArData[i] = &arData[i];
	}
	for (int i = 0; i < L; i++) {
		printf("%d\n", *PArData[i]);
	}*/






}