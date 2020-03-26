#include<stdio.h>
#include<string.h>
void main() {
	char nation[6] = "korea";
	//scanf("서식문자", 배열명) : 배열의 크기보다 입력받은 값이 커도 
	//							  다 대입된다. 데이터 손실!
	//scanf_s("%s", 배열명, sizeof(배열명))
	//배열의 크기보다 입력받은 값이 크면
	//아무것도 들어가지 않는다. 데이터 손실 방지!

	//printf("국가 : ");
	//scanf_s("%s", nation, sizeof(nation));

	//strcpy_s(nation, sizeof(nation), "china");


	//strcmp("값1", "값2");
	//0 : 두 문자열이 같을 때
	printf("%d\n", strlen(nation));

	//값1의 첫 문자가 값2의 첫 문자보다 클 때
	printf("%d\n",strcmp(nation, "china"));

	//0 : 두 문자열이 같을 때
	printf("%d\n", strcmp(nation, "korea"));

	//값 1의 첫 문자가 값2의 첫 문자보다 작을 때
	printf("%d\n", strcmp(nation, "rome"));


	


	printf("%s\n", nation);
}