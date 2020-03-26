#include<stdio.h>
void main() {
//메가박스
	const char* title = "▒MEGA BOX▒";
	const char* menu = "①예매하기\n②구매하기\n③쿠폰등록\n④나가기\n";
	const char* book_menu = "①겨울왕국2(09:00)\n②포드v페라리(13:00)\n③[청소년 관람 불가]남산의 부장들(23:00)\n④홈 화면으로\n";
	const char* food_menu = "①팝콘(￦7000)\n②콜라(￦3000)\n③[청소년 구매 불가]맥주(￦4000)\n④홈 화면으로\n";
	const char* errMsg = "다시 입력해주세요n";
	const char* name = "";
	int choice = 0;
	int money = 100000000;
	int t_price = 12000;
	int price = 0;
	int p_price = 7000;
	int c_price = 3000;
	int b_price = 4000;
	int age = 0;
	

	while (1) {
		printf("%s\n%s", title, menu);
		scanf_s("%d", &choice);


		if (choice == 4) {
			printf("다음에 또 오세요~\n");
			break;
		}

		switch (choice) {
		//예매하기
		case 1:
			//변수의 재사용
			//1. 메모리 효율성 증가
			//2. 가독성이 떨어진다.
			printf("%s", book_menu);
			scanf_s("%d", &choice);
			//Nested switch
			switch (choice) {
			//겨울왕국2(09:00)
			case 1:
				name = "겨울왕국2(09:00) 예매";
				break;
			//포드v페라리(13:00)
			case 2:
				name = "포드v페라리(13:00) 예매";
				break;
			//남산의 부장들(23:00)
			case 3:
				//나이 입력 후 19세 미만이면 실패처리
				printf("[청소년 관람 불가 영화입니다.]\n나이를 입력해주세요>>>\n");
				scanf_s("%d", &age);
				if (age < 19) {
					printf("19세 이상만 관람 가능합니다.\n");
					continue;
				}
				else {
					name = "남산의 부장들(23:00) 예매";
					break;
				}

			//홈 화면으로 이동
			case 4:
				continue;
			//그 외 영역
			default:
				printf("%s", errMsg);
				continue;
			}
			price = t_price;
			break;
		//구매하기
		case 2:
			printf("%s", food_menu);
			scanf_s("%d", &choice);
			switch (choice) {
			//팝콘(￦7000)
			case 1:
				name = "팝콘 구매";
				price = p_price;
				break;
			//콜라(￦3000)
			case 2:
				name = "콜라 구매";
				price = c_price;
				break;
			//맥주(￦4000) 청소년 구매 불가
			case 3:
				printf("[청소년 구매 불가 상품입니다.]\n나이를 입력해주세요>>>\n");
				scanf_s("%d", &age);
				if (age < 19) {
					printf("19세 이상만 구매 가능합니다.\n");
					continue;
				}
				else {
					name = "맥주 구매";
					price = b_price;
					break;
				}
			case 4:
				break;
			default:
				printf("%s", errMsg);
				break;
			}
			break;
		//쿠폰등록
		case 3:
			break;
		//나가기
		case 4:
			break;
		default:
			printf("%s\n", errMsg);
			continue;
		}
		//잔액부족 검사
		if (money < price) {
			printf("잔액부족!!!\n%s실패", name);
		}
		else {
			money -= price;
			printf("%s성공!!\n현재 잔액 : %d원\n", name, money);
		}
	}
}