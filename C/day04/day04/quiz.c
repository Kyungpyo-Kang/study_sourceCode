#include<stdio.h>
void main() {
	//Q.���� �� ���α׷��� �� �ƴѰ���?
/*	1. JAVA
	2. ���̽�
	3. C
	4. ���վ�
*/
	const char* quizMsg = "Q.���� �� ���α׷��� �� �ƴѰ���?\n1. JAVA\n2. ���̽�\n3. C\n4. ���վ�\n>>>";
	const char* quizMsg2 = "Q.���� �� �ѱ��� ������?\n1. �λ�\n2. �뱸\n3. ����\n4. ��õ\n>>>";
	int result = 0;
	printf("%s", quizMsg);
	scanf_s("%d", &result);

	//result == 4 ? printf("����!!!\n") : result > 4 || result < 1 ? printf("�߸� �Է��ϼ̽��ϴ�.\n") : printf("����..\n");
	
	if (result == 4) {
		printf("����!!!\n");
	}
	else if (result >= 1 && result <= 4) {
		printf("����..\n");
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}


	printf("%s", quizMsg2);
	scanf_s("%d", &result);
	//result == 3 ? printf("����!!!\n") : result > 4 || result < 1 ? printf("�߸� �Է��ϼ̽��ϴ�.\n") : printf("����..\n");
	if (result == 3) {
		printf("����!!!\n");
	}
	else if (result >= 1 && result <= 4) {
		printf("����..\n");
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}

}