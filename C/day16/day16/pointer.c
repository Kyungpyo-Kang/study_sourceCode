#include<stdio.h>

void function(int* PData) {
	*PData = 100;
}

void main() {
	int data = 10;

	//call by value : ���� ���� ȣ��
	//function(data);
	//call by address : �ּҰ��� ���� ȣ��
	function(&data);
	printf("%d\n", data); 
}