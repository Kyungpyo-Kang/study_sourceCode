#include<stdio.h>
void main() {
	//Q.다음 중 프로그래밍 언어가 아닌것은?
/*	1. JAVA
	2. 파이썬
	3. C
	4. 망둥어
*/
	const char* quizMsg = "Q.다음 중 프로그래밍 언어가 아닌것은?\n1. JAVA\n2. 파이썬\n3. C\n4. 망둥어\n>>>";
	const char* quizMsg2 = "Q.다음 중 한국의 수도는?\n1. 부산\n2. 대구\n3. 서울\n4. 인천\n>>>";
	int result = 0;
	printf("%s", quizMsg);
	scanf_s("%d", &result);

	//result == 4 ? printf("정답!!!\n") : result > 4 || result < 1 ? printf("잘못 입력하셨습니다.\n") : printf("오답..\n");
	
	if (result == 4) {
		printf("정답!!!\n");
	}
	else if (result >= 1 && result <= 4) {
		printf("오답..\n");
	}
	else {
		printf("잘못 입력하셨습니다.\n");
	}


	printf("%s", quizMsg2);
	scanf_s("%d", &result);
	//result == 3 ? printf("정답!!!\n") : result > 4 || result < 1 ? printf("잘못 입력하셨습니다.\n") : printf("오답..\n");
	if (result == 3) {
		printf("정답!!!\n");
	}
	else if (result >= 1 && result <= 4) {
		printf("오답..\n");
	}
	else {
		printf("잘못 입력하셨습니다.\n");
	}

}