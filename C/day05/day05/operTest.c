#include<stdio.h>
void main() {
	int data = 10;
	//printf("%d\n", data++);	//후위형은 해당 줄에서 적용이 안됨.
	printf("%d\n", ++data);	//전위형은 해당 줄에서 바로 적용이 됨.
}