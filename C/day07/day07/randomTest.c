#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main() {
	srand(time(NULL));

	for (int i = 0; i < 100; i++){
		printf("%d\n", rand() % 900000 + 100000);
	}
}