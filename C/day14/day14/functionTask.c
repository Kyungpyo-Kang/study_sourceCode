#include<stdio.h>
#include<string.h>
//5���� ���� �� �ִ밪 �ּҰ� ���ϱ�
int* temp;


int* getMaxMin(int arData[], int length) {
	int result[2] = { arData[0], arData[0] };
	
	for (int i = 1; i < length; i++) {
		if (result[1] < arData[i]) {
			result[1] = arData[i];
		} 
		if (result[0] > arData[i]) {
			result[0] = arData[i];
		}
	}
	return result;
}


/*


[���]
������ �ѱ۷� �ٲ��ִ� �Լ�
5���� ������ ������������ �����ϴ� �Լ�


*/
//	4�ڸ� ��
//	�ܺο��� ���ڿ� �迭�� �ּҰ��� ���޹޴´�.
void changeToHangle(int num, const char result[][3]) {
	//"��"~"��"���� ���ڿ� �迭�� ��´�.
	//�ܺο��� ���޹��� ���� num�� �� �ڸ��� ������ �ٷ� hangle�� �ε���
	//��ȣ�� Ȱ��ȴ�.
	//1024
	char hangle[10][3] = { "��", "��", "��", "��", "��", "��", "��", "ĥ", "��", "��" };
	int idx = 0;
	//num�� 0�̶�� ���� ��� �ڸ����� ������ ���ߴٴ� ���̴�.
	//num�� 0�� �� Ż��!
	while (num != 0) {
		
//		result[idx] = hangle[num % 10];
		//1024%10 ==4
		//1024/10 == 102

		//1�� �ڸ������� �������� ������ ������ �־��ֱ� ����
		//3-idx�� ���ش�.

		strcpy_s(result[3-idx], sizeof(result[3-idx]), hangle[num % 10]);
		//�۾� �Ϸ� �� 1�� �ڸ����� �����ش�.
		num /= 10;
		//�ε����� 1 ���������ش�.
		//3-idx : (3,2,1,0)
		idx++;
	}
}


//	5���� ������ ������������ �����ϴ� �Լ�



void sortASC(int arNum[], int length) {
	//i��° ���� ���� i+1���� j��° �濡 �ִ� ������ �� �� 
	//���� ���� �� ������ ��ġ�� �ٲ��༭ ������������ �����Ѵ�.

	for (int i = 0; i < length-1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (arNum[i] > arNum[j]) {
				//i��° ���� ���� ����� ���� temp�� ��Ƴ���
				//j��° �濡 temp ���� �ִ´�.
				//��, �� ������ �ִ� ���� ���� �ٲپ� �ִ� �۾�
				int temp = arNum[i];
				arNum[i] = arNum[j];
				arNum[j] = temp;
			}
		}
	}
	//3,4,5,2,1
	//1ȸ�� : 1,4,5,2,3
	//2ȸ�� : 1,2,5,4,3
	//3ȸ�� : 1,2,3,4,5
}

void sortDESC(int arNum[], int length) {
	for (int i = 0; i < length-1; i++) {
		for (int j = i+1; j < length; j++) {
			if (arNum[i] < arNum[j]) {
				int temp = arNum[i];
				arNum[i] = arNum[j];
				arNum[j] = temp;
			}
		}
	}
}




void main() {

	int arData[5] = { 3,4,5,2,1 };
	int length = sizeof(arData) / sizeof(int);
	//sortASC(arData, length);
	sortDESC(arData, length);
	for (int i = 0; i < length; i++) {
		printf("%d ", arData[i]);
	}
	printf("\n");


	/*char result[4][3] = { "", };
	changeToHangle(1024, result);
	for (int i = 0; i < 4; i++) {
		printf("%s\n", result[i]);
	}*/
	/*for (int i = 0; i < 4; i++) {
		printf("%s\n", result[i]);
	}*/


/*	int arData[5] = {5,3,1,8,3};
	int length = sizeof(arData) / sizeof(int);
	printf("�ִ� : %d\n", *getMaxMin(arData, length));
	printf("�ּڰ� : %d\n", *getMaxMin(arData, length) +1);*/



}