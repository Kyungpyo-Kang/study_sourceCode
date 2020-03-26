#define CNT 100


/*=============함수 선언부===============*/
/*재사용의 목적*/
char checkDup(char[]);
void insert(char[], int);
void update(char[], int, int);
void delete();
int select(char[], int[]);

/*소스코드 간결화*/
void printInsert();
void printUpdate();
void printDelete();
void printSelect();
void selectAll();
void cafe();
/*========================================*/



//extern 사용 시 초기값을 넣을 수 없다.
//중복 선언으로 간주된다.
extern char arName[CNT][100];
extern int arPrice[CNT];
extern int insertCnt;
extern int rowNum;




//소스코드 간결화 목적
void cafe() {
	char title[20] = "★Twosome place★";
	char menu[100] = "①추가하기\n②수정하기\n③삭제하기\n④검색하기\n⑤목록보기\n⑥나가기\n";
	char errMsg[30] = "다시 선택해주세요.\n";


	int  choice = 0;


	while (1) {
		printf("%s\n%s", title, menu);
		scanf_s("%d", &choice);

		//나가기
		if (choice == 6) { break; }
		switch (choice) {

			//추가하기
		case 1:
			printInsert();
			break;
			//수정하기
		case 2:
			printUpdate();
			break;
			//삭제하기
		case 3:
			printDelete();
			break;
			//검색하기
		case 4:
			printSelect();
			break;
			//목록보기
		case 5:
			selectAll();
			break;
			//오류
		default:
			printf(errMsg);
		}
	}
}



//중복확인
char checkDup(char temp[]) {
	//외부에서 문자열을 전달받아서 arName에 있는지 없는지 검사
	char isDup = '0';
	for (int i = 0; i < insertCnt; i++) {
		if (!strcmp(arName[i], temp)) {
			rowNum = i;
			//중복이 있다면 check는 '1'
			isDup = '1';
			break;
		}
	}
	return isDup;
}

void printInsert() {
	char isDup = ' ';
	char temp[100] = "";
	int price = 0;
	printf("상품명 : ");
	scanf_s("%s", temp, sizeof(temp));
	isDup = checkDup(temp);
	//중복이 없다면 참
	//문자 - 48 == 정수
	if (!(isDup - 48)) {
		printf("가격: ");
		scanf_s("%d", &price);
		insert(temp, price);
	}
	else {
		printf("중복된 상품명\n");
	}
}


//추가
//char insert(char temp[], int price) {	


void insert(char temp[], int price) {
	//char isDup = checkDup(temp);
	//char check = '0';
	//if (!(isDup - 48)) {

	//외부에서 중복검사 진행 후 isnert() 사용
	strcpy_s(arName[insertCnt], sizeof(arName[insertCnt]), temp);
	arPrice[insertCnt] = price;
	//총 상품갯수 1 증가
	insertCnt++;
	//check = '1';
	//}
	//return check;
}
//수정
void update(char temp[], int price, int choice) {
	//외부에서 새로운 상품명, 새로운 가격, 수정할 상품의 행번호를 전달 받는다.
	strcpy_s(arName[choice], sizeof(arName[choice]), temp);
	arPrice[choice] = price;
}

void printUpdate() {
	char temp[100] = "";
	char isDup = ' ';
	int choice = 0;
	int price = 0;

	printf("<수정하실 상품명>\n");
	scanf_s("%s", temp, sizeof(temp));
	isDup = checkDup(temp);
	//수정할 상품이 있는지(1번), 있다면 새로운 상품명이 중복되는지(2번)
	//총 checkDup()를 2번 사용하기 때문에 1번 rowNum을 기억해야 한다.
	//1번 rowNum이 수정할 행 번호이기 때문이다. 따라서 choice에 1번 rowNum을
	//저장한다.
	//만약 저장하지 않으면 2번 rowNum의 값이 변경될 수 있다.
	choice = rowNum;

	//1번
	if (isDup - 48) {
		printf("새로운 상품명: ");
		scanf_s("%s", temp, sizeof(temp));
		isDup = checkDup(temp);
		//2번
		if (!(isDup - 48)) {
			printf("새로운 가격: ");
			scanf_s("%d", &price);
			update(temp, price, choice);
		}
		else {
			printf("중복된 상품명입니다.\n");
		}
	}
	else {
		printf("수정하실 상품이 존재하지 않습니다.\n");
	}
}




//삭제
void delete() {
	for (int j = rowNum; j < insertCnt; j++) {
		//상품명 삭제
		strcpy_s(arName[j], sizeof(arName[j]), arName[j + 1]);
		//가격 삭제
		arPrice[j] = arPrice[j + 1];
	}
	insertCnt--;
}

void printDelete() {
	char temp[100] = "";
	char isDup = ' ';

	printf("삭제할 상품명 : ");
	scanf_s("%s", temp, sizeof(temp));

	isDup = checkDup(temp);

	if (!(isDup - 48)) {
		delete();
	}
	else {
		printf("삭제하실 상품이 존재하지 않습니다.\n");
	}
}
//검색
int select(char temp[], int arIdx[]) {
	int cnt = 0;

	for (int i = 0; i < insertCnt; i++) {
		//사용자가 입력한 키워드가 포함되어 있으면 모두 검색
		if (strstr(arName[i], temp) != NULL) {
			arIdx[cnt] = i;
			cnt++;
		}
	}
	return cnt;
}
void printSelect() {
	char temp[100] = "";
	int arIdx[100] = { 0, };
	int cnt = 0;
	printf("<검색할 상품명 입력>\n");
	scanf_s("%s", temp, sizeof(temp));


	cnt = select(temp, arIdx);
	for (int i = 0; i < cnt; i++) {
		printf("%s(%d)원\n", arName[arIdx[i]], arPrice[arIdx[i]]);
	}
	if (cnt == 0) {
		printf("검색결과 없음\n");
	}
}
//목록
void selectAll() {
	char temp[100] = "";
	printf("====================================\n");
	strcpy_s(temp, sizeof(temp), insertCnt == 0 ? "목록 없음" : "<상품명(가격)>\n");
	printf("%s\n", temp);
	for (int i = 0; i < insertCnt; i++) {
		//총 상품 개수만큼 순서대로 출력
		printf("%s(%d원)\n", arName[i], arPrice[i]);
	}
	printf("====================================\n");
}
