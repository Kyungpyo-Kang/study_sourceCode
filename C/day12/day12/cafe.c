#include<stdio.h>
#include<string.h>
#define CNT 100
void main() {
	//Create Read Update Delete
	//�߰�, ����, ����, �˻�, ���
	//��ǰ�� - ����
	//twosome place

	char title[20] = "��Twosome place��";
	char menu[100] = "���߰��ϱ�\n������ϱ�\n������ϱ�\n��˻��ϱ�\n���Ϻ���\n�쳪����\n";
	char errMsg[30] = "�ٽ� �������ּ���.\n";

	//��ǰ���� ������ ���ڿ� �迭
	char arName[CNT][100] = { "", };

	//��ǰ ������ ������ ���� �迭
	int arPrice[CNT] = { 0, };
	//����ڰ� �Է��� ��ǰ���� �ӽ÷� ������ ����
	char temp[100] = { ' ', };
	char resultName[CNT] = { "", };
	int resultPrice = 0;
	int choice = 0;
	//Flag
	int check = 0;

	//�߰��� ��ǰ�� �� ����
	int insertCnt = 0;

	//for�� �ۿ����� i�� ����ؾ� �ϹǷ� ���������� ����
	int i = 0;

	while (1) {
		check = 0;
		printf("%s\n%s", title, menu);
		scanf_s("%d", &choice);

		//������
		if (choice == 6) { break; }
		switch (choice) {

			//�߰��ϱ�
		case 1:
			printf("��ǰ�� : ");
			scanf_s("%s", temp, sizeof(temp));
			//���� ��ǰ�� �Ѱ��� ���ٸ� �ߺ��˻縦 �� �ʿ䰡 ����.
			if (insertCnt != 0) {
				//��ǰ�� �ϳ��� �ִٸ� ���´�.
				//�߰��� ��ǰ������ŭ �ݺ�
				for (i = 0; i < insertCnt; i++) {
					//����ڰ� �߰��� ��ǰ��� ��ġ�ϴ� ��ǰ���� �����ϸ� break
					if (!strcmp(arName[i], temp)) {
						break;
					}
				}
			}
			//������ break�� �����ٴ� ���� �ߺ��� ��ǰ�� �ִٴ� ��!
			//���� i �� insertCnt���� �����ϱ� ���ؼ��� �ߺ��� ����� �Ѵ�.
			if (i == insertCnt) {
				//�ߺ��� ������ ����
				printf("���� : ");
				scanf_s("%d", arPrice + insertCnt);
				strcpy_s(arName[insertCnt], sizeof(arName[insertCnt]), temp);
				//�߰� �Ϸ�� �� ��ǰ���� 1 ����
				insertCnt++;
			}
			else {
				printf("�ߺ��� ��ǰ��\n");
			}
			break;
			//�����ϱ�
		case 2:
			printf("<�����Ͻ� ��ǰ��>\n");
			scanf_s("%s", temp, sizeof(temp));
			for (i = 0; i < insertCnt; i++) {
				//������ ��ǰ�� �����ϸ� ��
				if (!strcmp(arName[i], temp)) {
					printf("���ο� ��ǰ�� : ");
					scanf_s("%s", temp, sizeof(temp));
					//���ο� ��ǰ�� �ߺ��˻�
					for (int j = 0; i < insertCnt; i++) {
						//���ο� ��ǰ���� �ߺ��Ǹ� ��
						if (!strcmp(arName[i], temp)) {
							printf("�ߺ��� ��ǰ��\n");
							check = 1;
						}
					}
					break;
				}
			}
			//���ο� ��ǰ�� �ߺ��� ���� �� ��
			if (check == 0) {
				strcpy_s(arName[i], sizeof(arName[i]), temp);
				printf("���ο� ���� : ");
				scanf_s("%d", arPrice + i);
			}
			break;
			//�����ϱ�
		case 3:
			printf("������ ��ǰ�� : ");
			scanf_s("%s", temp, sizeof(temp));

			//�� ��ǰ ������ŭ �ݺ�
			for (i = 0; i < insertCnt; i++) {
				//������ ��ǰ�� �ִ��� �˻�
				if (!strcmp(temp, arName[i])) {
					//������ ��ǰ�� �ִٸ� �� ��ǰ�࿡ ���� ���� ������.
					//insertCnt��° ����� �ݺ��Ѵ�.
					for (int j = i; j < insertCnt; j++) {
						//��ǰ�� ����
						strcpy_s(arName[i], sizeof(arName[i]), arName[i + 1]);
						//���� ����
						arPrice[i] = arPrice[i + 1];
					}
					//���� �Ϸ� �� �� ��ǰ���� 1 ����
					insertCnt--;
					break;
				}
			}
			//������ ������ ��ǰ�� ���ٸ� ���� �޽��� ���
			if (i == insertCnt) {
				printf("�����Ͻ� ��ǰ�� �������� �ʽ��ϴ�.\n");
			}
			break;
			//�˻��ϱ�
		case 4:
			printf("<�˻��� ��ǰ�� �Է�>\n");
			scanf_s("%s", temp, sizeof(temp));
			if (insertCnt != 0) {
				for (i = 0; i < insertCnt; i++) {
					//if (!strcmp(arName[i], temp)) {
					//����ڰ� �Է��� Ű���尡 ���ԵǾ� ������ ��� �˻�
					if(strstr(arName[i], temp) != NULL) {
						strcpy_s(resultName, sizeof(resultName), arName[i]);
						resultPrice = arPrice[i];
						check = 1;
						//break;
					}
					/*if (i==insertCnt) {
						result = 0;
					}*/
				}
			}
			else {
				check = -1;
			}

			switch (check) {
			case -1:
				printf("��ǰ�� ���� ������ּ���!\n");
				break;
			case 0:
				printf("�˻��� ��ǰ�� �������� �ʽ��ϴ�.\n");
				break;
			case 1:
				printf("====================================\n");
				printf("<�˻�����>\n");
				printf("��ǰ�� : %s\n��ǰ���� : %d��\n", resultName, resultPrice);
				printf("====================================\n");
				break;
			}

			break;
			//��Ϻ���
		case 5:
			//���� �� ��ǰ������ 0����� ��Ͼ����� ��µǰ� 1���� �ִٸ� <��ǰ��(����)>�� ��µȴ�.
			printf("====================================\n");
			strcpy_s(temp, sizeof(temp), insertCnt == 0 ? "��� ����" : "<��ǰ��(����)>\n");
			printf("%s\n", temp);
			for (i = 0; i < insertCnt; i++) {
				//�� ��ǰ ������ŭ ������� ���
				printf("%s(%d��)\n", arName[i], arPrice[i]);
			}
			printf("====================================\n");
			break;
			//����
		default:
			printf(errMsg);
		}
	}




}