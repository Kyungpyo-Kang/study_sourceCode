#include<stdio.h>
#define ROW 2
#define COL 3
void main() {
	int arrData[2][3] = { {3,4,5},{9,8,7} };
	int length = ROW * COL;

	for (int i = 0; i < length; i++) {
		//За : 000 111	012345 / i : i/3
		//ї­ : 012 012	012345 % i : i%3
		arrData[i / 3][i % 3] =  (i + 1)*2 ;
	}

	for (int i = 0; i < length; i++) {
		if (i % 3 == 0 && i != 0) { printf("\n"); }

		printf("%02d ", arrData[i / 3][i % 3]);
	}
	printf("\n");


}