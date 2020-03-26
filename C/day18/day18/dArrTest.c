#include<stdio.h>
#include<stdlib.h>

void main() {
	int** dArr = (int**)malloc(sizeof(int*)*2);

	for (int i = 0; i < 2; i++) {
		dArr[i] = (int*)malloc(sizeof(int) * 3);
	}

	for (int i = 0; i < 2; i++) {
		free(dArr[i]);
	}
	free(dArr);
}