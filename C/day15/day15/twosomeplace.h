#define CNT 100


/*=============�Լ� �����===============*/
/*������ ����*/
char checkDup(char[]);
void insert(char[], int);
void update(char[], int, int);
void delete();
int select(char[], int[]);

/*�ҽ��ڵ� ����ȭ*/
void printInsert();
void printUpdate();
void printDelete();
void printSelect();
void selectAll();
void cafe();
/*========================================*/



//extern ��� �� �ʱⰪ�� ���� �� ����.
//�ߺ� �������� ���ֵȴ�.
extern char arName[CNT][100];
extern int arPrice[CNT];
extern int insertCnt;
extern int rowNum;




//�ҽ��ڵ� ����ȭ ����
void cafe() {
	char title[20] = "��Twosome place��";
	char menu[100] = "���߰��ϱ�\n������ϱ�\n������ϱ�\n��˻��ϱ�\n���Ϻ���\n�쳪����\n";
	char errMsg[30] = "�ٽ� �������ּ���.\n";


	int  choice = 0;


	while (1) {
		printf("%s\n%s", title, menu);
		scanf_s("%d", &choice);

		//������
		if (choice == 6) { break; }
		switch (choice) {

			//�߰��ϱ�
		case 1:
			printInsert();
			break;
			//�����ϱ�
		case 2:
			printUpdate();
			break;
			//�����ϱ�
		case 3:
			printDelete();
			break;
			//�˻��ϱ�
		case 4:
			printSelect();
			break;
			//��Ϻ���
		case 5:
			selectAll();
			break;
			//����
		default:
			printf(errMsg);
		}
	}
}



//�ߺ�Ȯ��
char checkDup(char temp[]) {
	//�ܺο��� ���ڿ��� ���޹޾Ƽ� arName�� �ִ��� ������ �˻�
	char isDup = '0';
	for (int i = 0; i < insertCnt; i++) {
		if (!strcmp(arName[i], temp)) {
			rowNum = i;
			//�ߺ��� �ִٸ� check�� '1'
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
	printf("��ǰ�� : ");
	scanf_s("%s", temp, sizeof(temp));
	isDup = checkDup(temp);
	//�ߺ��� ���ٸ� ��
	//���� - 48 == ����
	if (!(isDup - 48)) {
		printf("����: ");
		scanf_s("%d", &price);
		insert(temp, price);
	}
	else {
		printf("�ߺ��� ��ǰ��\n");
	}
}


//�߰�
//char insert(char temp[], int price) {	


void insert(char temp[], int price) {
	//char isDup = checkDup(temp);
	//char check = '0';
	//if (!(isDup - 48)) {

	//�ܺο��� �ߺ��˻� ���� �� isnert() ���
	strcpy_s(arName[insertCnt], sizeof(arName[insertCnt]), temp);
	arPrice[insertCnt] = price;
	//�� ��ǰ���� 1 ����
	insertCnt++;
	//check = '1';
	//}
	//return check;
}
//����
void update(char temp[], int price, int choice) {
	//�ܺο��� ���ο� ��ǰ��, ���ο� ����, ������ ��ǰ�� ���ȣ�� ���� �޴´�.
	strcpy_s(arName[choice], sizeof(arName[choice]), temp);
	arPrice[choice] = price;
}

void printUpdate() {
	char temp[100] = "";
	char isDup = ' ';
	int choice = 0;
	int price = 0;

	printf("<�����Ͻ� ��ǰ��>\n");
	scanf_s("%s", temp, sizeof(temp));
	isDup = checkDup(temp);
	//������ ��ǰ�� �ִ���(1��), �ִٸ� ���ο� ��ǰ���� �ߺ��Ǵ���(2��)
	//�� checkDup()�� 2�� ����ϱ� ������ 1�� rowNum�� ����ؾ� �Ѵ�.
	//1�� rowNum�� ������ �� ��ȣ�̱� �����̴�. ���� choice�� 1�� rowNum��
	//�����Ѵ�.
	//���� �������� ������ 2�� rowNum�� ���� ����� �� �ִ�.
	choice = rowNum;

	//1��
	if (isDup - 48) {
		printf("���ο� ��ǰ��: ");
		scanf_s("%s", temp, sizeof(temp));
		isDup = checkDup(temp);
		//2��
		if (!(isDup - 48)) {
			printf("���ο� ����: ");
			scanf_s("%d", &price);
			update(temp, price, choice);
		}
		else {
			printf("�ߺ��� ��ǰ���Դϴ�.\n");
		}
	}
	else {
		printf("�����Ͻ� ��ǰ�� �������� �ʽ��ϴ�.\n");
	}
}




//����
void delete() {
	for (int j = rowNum; j < insertCnt; j++) {
		//��ǰ�� ����
		strcpy_s(arName[j], sizeof(arName[j]), arName[j + 1]);
		//���� ����
		arPrice[j] = arPrice[j + 1];
	}
	insertCnt--;
}

void printDelete() {
	char temp[100] = "";
	char isDup = ' ';

	printf("������ ��ǰ�� : ");
	scanf_s("%s", temp, sizeof(temp));

	isDup = checkDup(temp);

	if (!(isDup - 48)) {
		delete();
	}
	else {
		printf("�����Ͻ� ��ǰ�� �������� �ʽ��ϴ�.\n");
	}
}
//�˻�
int select(char temp[], int arIdx[]) {
	int cnt = 0;

	for (int i = 0; i < insertCnt; i++) {
		//����ڰ� �Է��� Ű���尡 ���ԵǾ� ������ ��� �˻�
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
	printf("<�˻��� ��ǰ�� �Է�>\n");
	scanf_s("%s", temp, sizeof(temp));


	cnt = select(temp, arIdx);
	for (int i = 0; i < cnt; i++) {
		printf("%s(%d)��\n", arName[arIdx[i]], arPrice[arIdx[i]]);
	}
	if (cnt == 0) {
		printf("�˻���� ����\n");
	}
}
//���
void selectAll() {
	char temp[100] = "";
	printf("====================================\n");
	strcpy_s(temp, sizeof(temp), insertCnt == 0 ? "��� ����" : "<��ǰ��(����)>\n");
	printf("%s\n", temp);
	for (int i = 0; i < insertCnt; i++) {
		//�� ��ǰ ������ŭ ������� ���
		printf("%s(%d��)\n", arName[i], arPrice[i]);
	}
	printf("====================================\n");
}
