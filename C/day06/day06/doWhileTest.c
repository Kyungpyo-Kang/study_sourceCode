#include<stdio.h>
void main() {
	int choice = 0;
	const char* msg = "1.�����ȸ\n2.�нǽŰ�\n0.���� ����\n";

	do {
		printf("%s", msg);
		scanf_s("%d", &choice);
	} while (choice != 0);
}