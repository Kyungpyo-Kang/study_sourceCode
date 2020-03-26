#include<stdio.h>
#include<string.h>
//유휴메모리를 없애기 위해서 1byte씩 증가하도록 하는 명령어
#pragma pack(push, 1)
void main() {
	// 구조체 안에 있는 멤버변수 중 byte 수가 가장 큰 것으로
	// 용량이 증가한다. 따라서 42byte만 할당하면 되는 것을
	// 8byte 용량으로 늘어나기 때문에 총 크기는 48 byte가 된다.
	// 6byte가 바로 유휴메모리이다.
	/*struct Animal {
		char name[30];
		int age;
		double weight;
	};*/


	typedef struct Animal {
		char name[30];
		int age;
		double weight;
	}tag_Animal;

	tag_Animal dog = { "찰리",3,2.76 };
	printf("%d\n", sizeof(dog));
	strcpy_s(dog.name, sizeof(dog.name), "찰스");
	printf("%s\n", dog.name);
	printf("%d\n", dog.age);
}