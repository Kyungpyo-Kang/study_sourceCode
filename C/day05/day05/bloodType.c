#include<stdio.h>
void main() {
	//����� ��������?
	//1. A
	//2. B
	//3. O 
	//4. AB
	const char* qMsg = "����� ��������?\n1.A\n2.B\n3.O\n4.AB\n";
	int choice = 0;

	const char* a_msg = "�����ϰ� �Ĳ��ϴ�.";
	const char* b_msg = "�������� ����.";
	const char* o_msg = "�米���� ����.";
	const char* ab_msg = "���ϴ�.";
	const char* errMsg = "�߸� �Է��ϼ̽��ϴ�.";

	printf("%s", qMsg);
	scanf_s("%d", &choice);


	switch (choice) {
		case 1 :
			printf("%s\n", a_msg);
			break;
		case 2:
			printf("%s\n", b_msg);
			break;
		case 3:
			printf("%s\n", o_msg);
			break;
		case 4:
			printf("%s\n", ab_msg);
			break;
		default:
			printf("%s\n", errMsg); 
	}

	/*if (choice == 1) {
		printf("%s\n", a_msg);
	}
	else if (choice == 2) {
		printf("%s\n", b_msg);
	}
	else if (choice == 3) {
		printf("%s\n", o_msg);
	}
	else if (choice == 4) {
		printf("%s\n", ab_msg);
	}
	else {
		printf("%s\n", errMsg);
	}*/



}