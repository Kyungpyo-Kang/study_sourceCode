#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main() {
	//메가박스
	const char* title = "▒MEGA BOX▒";
	const char* menu = "①예매하기\n②구매하기\n③쿠폰등록\n④나가기\n";
	const char* book_menu = "①겨울왕국2(09:00)\n②포드v페라리(13:00)\n③[청소년 관람 불가]남산의 부장들(23:00)\n④홈 화면으로\n";
	const char* food_menu = "①팝콘(￦7000)\n②콜라(￦3000)\n③[청소년 구매 불가]맥주(￦4000)\n④홈 화면으로\n";
	const char* errMsg = "다시 입력해주세요";
	const char* name = "";
	int choice = 0;
	int money = 100000000;

	//상품 가격
	int t_price = 12000;
	int p_price = 7000;
	int c_price = 3000;
	int b_price = 4000;

	//사용자가 선택한 상품의 가격을 담아줄 변수
	int price = 0;

	int age = 0;

	//회사 쿠폰
	int coupon =0;
	//사용자가 입력한 쿠폰 번호
	int myCoupon = 0;
	//사용자의 쿠폰 등록 여부를 검사하는 Flag
	int coupon_check = 0;
	//사용자가 팝콘을 선택했는지 검사하는 Flag
	int popcorn_check = 0;
	//이전 쿠폰 번호를 저장할 변수
	int temp = 0;

	//기준점을 시간(변수)으로 설정하는 코드
	srand(time(NULL));
	//100000 ~ 999999		6자리 수의 쿠폰번호
	//0 ~ 899999 + 100000
	coupon = rand()%900000 + 100000;


	while (1) {
		//이전에 팝콘을 구매한 표시가 남아있지 않도록 하기 위해
		//매 반복마다 0으로 초기화 해준다.
		//만약 초기화하지 않는다면 다음 로직에 문제 발생
		popcorn_check = 0;
		/*테스터영역*/

		printf("%d\n", coupon);
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
			//Nested switch(중첩 스위치문)
			switch (choice) {
				//겨울왕국2(09:00)
			case 1:
				//사용자가 선택한 영화 관련 메시지를 name에 담아준다.
				//하단에서 일괄처리를 할 때 사용자가 선택한 영화가 필요하기 때문!
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
				//만약 if문에 들어간다면 하단의 결제영역까지 가지 못한다.
				//따라서 미성년자가 아닐 경우에는 if문에 들어가지 않기 때문에
				//결제 영역까지 정상적으로 내려간다.
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
				//continue를 사용하는 이유
				//밑의 코드를 실행하지 않고 다음 반복으로 스킵
				//다음 반복에는 홈 화면부터 나오기 때문!
				continue;
				//그 외 영역
			default:
				printf("%s", errMsg);
				continue;
			}
			//사용자가 정상적으로 선택했다면 올 수 있는 영역
			//모든 영화표 가격은 동일하기 때문에 이 영역에서
			//price에 영화표 가격을 담아준다.
			price = t_price;
			break;
			//구매하기
		case 2:
			printf("%s", food_menu);
			scanf_s("%d", &choice);
			switch (choice) {
				//팝콘(￦7000)
			case 1:
				//사용자가 팝콘을 선택했다면 popcorn_check를 1로 변경
				popcorn_check = 1;
				name = "팝콘 구매";
				//영화표와 다르게 상품은 가격이 모두 다르다.
				//따라서 사용자가 선택한 상품 관련 메세지 뿐만 아니라
				//가격도 각각 담아준다.
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
			//쿠폰등록 영역
		case 3:

			//6자리 쿠폰
			//팝콘 무료쿠폰
			//랜덤한 쿠폰번호 생성>> 사용자가 입력한 쿠폰번호와 비교
			//같으면 팝콘 구매 시 무료
			//이미 쿠폰이 있을 때 쿠폰 등록 불가능
			//쿠폰 사용 시 랜덤한 쿠폰번호 다시 생성


			//사용자가 쿠폰을 이미 등록했다면 coupon_check에
			//1이라는 값이 들어가 있다. 따라서 1은 !(not)을 만나 0이 되고
			//이미 등록한 사람은 if문 안으로 들어갈 수 없다.
			//따라서 쿠폰을 소지하지 않은 사용자만 쿠폰을 등록할 수 있다.
			if (!coupon_check) {
				printf("쿠폰 번호 : ");
				scanf_s("%d", &myCoupon);

				//사용자가 입력한 쿠폰번호와 회사 쿠폰을 비교하여
				//일치하면 coupon_check를 1로 변경해준다.
				if (coupon == myCoupon) {
					//Flag
					coupon_check = 1;
					printf("팝콘 무료쿠폰 등록 성공!!\n");
				}
				else {
					printf("잘못된 쿠폰번호 입니다.\n");
				}
			}
			else {
				printf("이미 등록하셨습니다.\n");
			}
			continue;
			//나가기
		case 4:
			break;
		default:
			printf("%s\n", errMsg);
			continue;
		}
		//쿠폰 검사

		//사용자가 쿠폰을 소지하고 있는지 && 팝콘을 구매하려고 하는지
		//둘 다 참이면 아래 영역에 들어간다.
		if (coupon_check && popcorn_check) {
			//쿠폰이 자동으로 사용됐으므로
			//coupon_check를 다시 0으로 초기화
			coupon_check = 0;

			//팝콘의 가격을 0으로 초기화
			price = 0;

			//사용된 쿠폰번호를 temp에 저장
			temp = coupon;
			do {
				//새로운 쿠폰 번호를 만들어준다.
				coupon = rand() % 900000 + 100000;

				//이전 쿠폰번호와 중복되지 않을 때까지 무한 반복
				//즉, 중복되지 않으면 탈출한다.
			} while (temp == coupon);
		}
		//잔액부족 검사
		//위에서 사용자가 선택한 상품에 대한 정보가
		//name과 price에 담겨서 내려오기 때문에
		//일괄처리가 가능하다.
		if (money < price) {
			printf("잔액부족!!!\n%s실패", name);
		}
		else {
			money -= price;
			printf("%s성공!!\n현재 잔액 : %d원\n", name, money);
		}
	}
}