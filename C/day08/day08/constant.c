#include<stdio.h>
#define LENGTH 4		//���� ���Ͽ��� 4 ��ſ� LENGTH�� ���ڴ�.		��	��ó�� ��ɾ�
void main() {
	//����
	int data1 = 10;
	//���
	const int data2 = 4;
	// data2 = 100;		����

	//int arData[data2] = { 1,3,4,5 };		�迭�� �޸𸮿� ���� ���� �Ҵ�Ǳ� ������ �տ��� ��� data2�� �����ص� ������ ����.
	int arData[LENGTH] = { 1,3,4,5 };		//LENGTH�� ��ó�� ��ɾ ���ؼ� ���� ���� �޸𸮿� �Ҵ�Ǿ��� ������ ������ ���� �ʴ´�.



}