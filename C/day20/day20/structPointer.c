#include<stdio.h>

typedef struct Food {
	char name[30];
	int price;
	char taste[30];
}tag_Food;



void main() {
	tag_Food salmon = { "����ȸ", 29900, "�����" };
	tag_Food* PSalmon = &salmon;
	PSalmon -> price = 20000;
	printf("%s\n", PSalmon->name);
	printf("%d��\n", PSalmon->price);
	printf("%s��\n", PSalmon->taste);

}