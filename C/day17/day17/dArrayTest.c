#include<stdio.h>
#include<stdlib.h>

void main() {
	int* dAr = (int*)malloc(sizeof(int) * 5);
	dAr = (int*)realloc(dAr, sizeof(int) * 6);
	free(dAr);

	dAr = calloc(6, sizeof(int));

	for (int i = 0; i < 6; i++) {
		printf("%d\n", dAr[i]);
	}
	free(dAr);




}