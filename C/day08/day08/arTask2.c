#include<stdio.h>
#define L1 10
#define L2 100
#define L3 6
#define L4 26



void main() {

	//1~10���� �ְ� ���	L1
	/*int arData[L1] = { 0, };
	for (int i = 0; i < L1; i++)
	{
		arData[i] = i + 1;
	}
	for (int i = 0; i < L1; i++)
	{
		printf("%d \n", arData[i]);
	}
	printf("\n");*/

	//10~1���� �ְ� ���	L1
	/*int arData[L1] = { 0, };
	for (int i = 0; i < L1; i++)
	{
		arData[i] = 10-i;
	}
	for (int i = 0; i < L1; i++)
	{
		printf("%d ", arData[i]);
	}
	printf("\n");*/
	//1~100���� ���� �� ���� ���ϱ�	L2

	/*int arData[L2] = { 0, };
	int result = 0;
	for (int i = 0; i < L2; i++)
	{
		arData[i] = i+1;
		result += arData[i];
	}
	
	printf("%d\n", result);*/

	//A~F���� �ְ� ���		L3
	//int arData[L3] = { 0, };
	/*char arData[L3] = {' ', };
	for (int i = 0; i < L3; i++)
	{
		arData[i] = i+65;
	}
	for (int i = 0; i < L3; i++)
	{
		printf("%c ", arData[i]);
	}*/

	//A~F���� �� E�����ϰ� ���

	//int arData[L3] = { 0, };
	/*char arData[L3] = {' ', };


	for (int i = 0; i < L3; i++)
	{
		arData[i] = i + 65;
	}
	for (int i = 0; i < L3; i++)
	{
		if (i == 4) {
			continue;
		}
		printf("%c ", arData[i]);
	}
	printf("\n");*/

	//aBcDe.....Z �ְ� ���		L4
	/*int arData[L4] = { 0, };

	for (int i = 0; i < L4; i++)
	{
		
		arData[i] = i % 2 != 0 ? i + 65 : i + 97;
	}
	for (int i = 0; i < L4; i++)
	{
		printf("%c ", arData[i]);
	}
	printf("\n");*/



}