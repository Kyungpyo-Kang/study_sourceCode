#include<stdio.h>
#define L 5

void main() {
	//1~10���� �� ¦���� �迭�� �ְ� ����ϱ�

	int arData[L] = { 0, };

	for (int i = 0; i < L; i++) {
		arData[i] = (i + 1) * 2;
	}
	
	/*printf("%p\n", arData);
	printf("%p\n", &arData[0]);
	printf("%p\n", arData + 1);
	printf("%d\n", *(arData + 1));*/

	//arData�� ����ִ� �� ������ �������� ����ϱ�
	//���ȣ�� ������� �ʴ´�.
	for (int i = 0; i < L; i++) {
		printf("%d ", *(arData + i));
	}
	printf("\n");



}








