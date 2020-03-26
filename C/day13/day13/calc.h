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

//두 정수의 나눗셈 : 몫과 나머지 각각 printf로 출력해주는 함수

void divide(int num1, int num2) {
	
	if(num2 == 0 ) {
		printf("0으로 나눌 수 없습니다.\n");
	}
	else {
		printf("몫\t: %d\n", num1 / num2);
		printf("나머지\t: %d\n", num1%num2);
	}
}

