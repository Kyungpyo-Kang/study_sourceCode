#include<stdio.h>
void main() {
	int arData[] = {3,4,5};
	int length = sizeof(arData) / sizeof(int);

	for (int i = 0; i < length; i++) {
		arData[i] = 3 - i;
	}

	for (int i = 0; i < length; i++){
		printf("%d\n", arData[i]);
	}

}