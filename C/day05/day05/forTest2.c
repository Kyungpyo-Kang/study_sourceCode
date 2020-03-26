#include<stdio.h>
void main() {
	//1~10까지 중 4까지만 출력하기
	/*for (int i = 0; i < 10; i++){
		printf("%d\n", i + 1);
		if (i == 3) {
			break;
		}
	}*/
	//1~10까지 중 4 제외하고 출력하기
	for (int i = 0; i < 10; i++){
		if (i == 3) {
			continue;
		}
		printf("%d\n", i + 1);
	}
}