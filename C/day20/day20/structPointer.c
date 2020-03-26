#include<stdio.h>

typedef struct Food {
	char name[30];
	int price;
	char taste[30];
}tag_Food;



void main() {
	tag_Food salmon = { "연어회", 29900, "물고기" };
	tag_Food* PSalmon = &salmon;
	PSalmon -> price = 20000;
	printf("%s\n", PSalmon->name);
	printf("%d원\n", PSalmon->price);
	printf("%s맛\n", PSalmon->taste);

}