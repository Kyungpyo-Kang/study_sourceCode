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

	printf("%s\n", choice == 1 ? a_msg :
		choice == 2 ? b_msg :
		choice == 3 ? o_msg :
		choice == 4 ? ab_msg :
		errMsg);

	
		
}