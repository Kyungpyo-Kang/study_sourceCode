#include<stdio.h>
void main() {
	int choice = 0;
	const char* msg = "1.요금조회\n2.분실신고\n0.상담원 연결\n";

	do {
		printf("%s", msg);
		scanf_s("%d", &choice);
	} while (choice != 0);
}