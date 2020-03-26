#include<stdio.h>

void function(int* PData) {
	*PData = 100;
}

void main() {
	int data = 10;

	//call by value : 값에 의한 호출
	//function(data);
	//call by address : 주소값에 의한 호출
	function(&data);
	printf("%d\n", data); 
}