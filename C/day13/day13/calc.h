int add(int num1, int num2) {
	int result = num1 + num2;
	return result;
}


int subt(int num1, int num2) {
	int result = num1 - num2;
	return result;
}


int mult(int num1, int num2) {
	int result = num1 * num2;
	return result;
}

//�� ������ ������ : ��� ������ ���� printf�� ������ִ� �Լ�

void divide(int num1, int num2) {
	
	if(num2 == 0 ) {
		printf("0���� ���� �� �����ϴ�.\n");
	}
	else {
		printf("��\t: %d\n", num1 / num2);
		printf("������\t: %d\n", num1%num2);
	}
}

