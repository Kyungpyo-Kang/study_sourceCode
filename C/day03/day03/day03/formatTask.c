#include<stdio.h>

void main() {

	const char* nameMsg = "애완동물 이름 : ";
	const char* ageMsg = "나이 : ";
	const char* weightMsg = "몸무게 : ";
	const char* moodMsg = "기분 : ";

	const char* name = "뽀삐 ";
	int age = 8;
	double weight = 3.95;
	char mood = 'A';

	printf("%s%s\n", nameMsg,name);
	printf("%s%s%d\n", name,ageMsg,age);
	printf("%s%s%.2fkg\n", name,weightMsg, weight);
	printf("%s%s%c\n", name,moodMsg, mood);

}