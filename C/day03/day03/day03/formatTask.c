#include<stdio.h>

void main() {

	const char* nameMsg = "�ֿϵ��� �̸� : ";
	const char* ageMsg = "���� : ";
	const char* weightMsg = "������ : ";
	const char* moodMsg = "��� : ";

	const char* name = "�ǻ� ";
	int age = 8;
	double weight = 3.95;
	char mood = 'A';

	printf("%s%s\n", nameMsg,name);
	printf("%s%s%d\n", name,ageMsg,age);
	printf("%s%s%.2fkg\n", name,weightMsg, weight);
	printf("%s%s%c\n", name,moodMsg, mood);

}