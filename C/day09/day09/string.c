#include<stdio.h>
void main() {
	//const char nation[6] = "korea";
	char nation[6] = "korea";


	//�����ؼ� �����ϴ� ���� �����ش�.
	//���� scanf_s()�� �Է¹��� �� ����.
	const char* natin2 = "japan";


	//�������ڷ��� �տ� const�� �������
	//�����͸� �տ� const�� ��� -> �ּҰ��� ������ �� ����.
	const char* const nation3 = "china";
		
	printf("%s\n", nation);
	
	nation2 = "korea";
	nation3 = "korea";
	//nation = "japan";


}