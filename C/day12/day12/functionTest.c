#include<stdio.h>

int f(int);
//main() : ���� ���α׷��� ������ִ� ���
void main() {
	int result = f(10) + 3;
	printf("%d\n",result);
}
int f(int x) {
	printf("f�Լ��Դϴ�.\n");
	return 2 * x + 1;
}


