#include<stdio.h>
void main() {
	//당신의 혈액형은?
	//1. A
	//2. B
	//3. O 
	//4. AB
	const char* qMsg = "당신의 혈액형은?\n1.A\n2.B\n3.O\n4.AB\n";
	int choice = 0;

	const char* a_msg = "섬세하고 꼼꼼하다.";
	const char* b_msg = "추진력이 좋다.";
	const char* o_msg = "사교성이 좋다.";
	const char* ab_msg = "착하다.";
	const char* errMsg = "잘못 입력하셨습니다.";

	printf("%s", qMsg);
	scanf_s("%d", &choice);

	printf("%s\n", choice == 1 ? a_msg :
		choice == 2 ? b_msg :
		choice == 3 ? o_msg :
		choice == 4 ? ab_msg :
		errMsg);

	
		
}