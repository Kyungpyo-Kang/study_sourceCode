#include<stdio.h>
#include<stdlib.h>

void main() {
	//������ �Է¹ް� �׸�ŭ �迭 �Ҵ��ϱ�
	int cnt = 0;
	int* dArNum = 0;

	printf("������ �Է����ּ��� : ");
	scanf_s("%d", &cnt);
	dArNum = (int*)malloc(sizeof(int)*cnt);
	


	for (int i = 0; i < cnt; i++) {
		printf("%d��° ���� : ", i + 1);
		scanf_s("%d", dArNum+i);
	}
	printf("\n");

	for (int i = 0; i < cnt; i++) {
		printf("%d\n", dArNum[i]);
	}

	free(dArNum);

}

