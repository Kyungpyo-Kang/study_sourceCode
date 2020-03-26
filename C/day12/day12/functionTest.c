#include<stdio.h>

int f(int);
//main() : 실행 프로그램을 만들어주는 기능
void main() {
	int result = f(10) + 3;
	printf("%d\n",result);
}
int f(int x) {
	printf("f함수입니다.\n");
	return 2 * x + 1;
}


