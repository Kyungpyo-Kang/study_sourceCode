#include<stdio.h>
#include<string.h>
//���޸޸𸮸� ���ֱ� ���ؼ� 1byte�� �����ϵ��� �ϴ� ��ɾ�
#pragma pack(push, 1)
void main() {
	// ����ü �ȿ� �ִ� ������� �� byte ���� ���� ū ������
	// �뷮�� �����Ѵ�. ���� 42byte�� �Ҵ��ϸ� �Ǵ� ����
	// 8byte �뷮���� �þ�� ������ �� ũ��� 48 byte�� �ȴ�.
	// 6byte�� �ٷ� ���޸޸��̴�.
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

	tag_Animal dog = { "����",3,2.76 };
	printf("%d\n", sizeof(dog));
	strcpy_s(dog.name, sizeof(dog.name), "����");
	printf("%s\n", dog.name);
	printf("%d\n", dog.age);
}