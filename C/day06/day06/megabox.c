#include<stdio.h>
void main() {
//�ް��ڽ�
	const char* title = "��MEGA BOX��";
	const char* menu = "�翹���ϱ�\n�豸���ϱ�\n���������\n�곪����\n";
	const char* book_menu = "��ܿ�ձ�2(09:00)\n������v���(13:00)\n��[û�ҳ� ���� �Ұ�]������ �����(23:00)\n��Ȩ ȭ������\n";
	const char* food_menu = "������(��7000)\n���ݶ�(��3000)\n��[û�ҳ� ���� �Ұ�]����(��4000)\n��Ȩ ȭ������\n";
	const char* errMsg = "�ٽ� �Է����ּ���n";
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
			printf("������ �� ������~\n");
			break;
		}

		switch (choice) {
		//�����ϱ�
		case 1:
			//������ ����
			//1. �޸� ȿ���� ����
			//2. �������� ��������.
			printf("%s", book_menu);
			scanf_s("%d", &choice);
			//Nested switch
			switch (choice) {
			//�ܿ�ձ�2(09:00)
			case 1:
				name = "�ܿ�ձ�2(09:00) ����";
				break;
			//����v���(13:00)
			case 2:
				name = "����v���(13:00) ����";
				break;
			//������ �����(23:00)
			case 3:
				//���� �Է� �� 19�� �̸��̸� ����ó��
				printf("[û�ҳ� ���� �Ұ� ��ȭ�Դϴ�.]\n���̸� �Է����ּ���>>>\n");
				scanf_s("%d", &age);
				if (age < 19) {
					printf("19�� �̻� ���� �����մϴ�.\n");
					continue;
				}
				else {
					name = "������ �����(23:00) ����";
					break;
				}

			//Ȩ ȭ������ �̵�
			case 4:
				continue;
			//�� �� ����
			default:
				printf("%s", errMsg);
				continue;
			}
			price = t_price;
			break;
		//�����ϱ�
		case 2:
			printf("%s", food_menu);
			scanf_s("%d", &choice);
			switch (choice) {
			//����(��7000)
			case 1:
				name = "���� ����";
				price = p_price;
				break;
			//�ݶ�(��3000)
			case 2:
				name = "�ݶ� ����";
				price = c_price;
				break;
			//����(��4000) û�ҳ� ���� �Ұ�
			case 3:
				printf("[û�ҳ� ���� �Ұ� ��ǰ�Դϴ�.]\n���̸� �Է����ּ���>>>\n");
				scanf_s("%d", &age);
				if (age < 19) {
					printf("19�� �̻� ���� �����մϴ�.\n");
					continue;
				}
				else {
					name = "���� ����";
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
		//�������
		case 3:
			break;
		//������
		case 4:
			break;
		default:
			printf("%s\n", errMsg);
			continue;
		}
		//�ܾ׺��� �˻�
		if (money < price) {
			printf("�ܾ׺���!!!\n%s����", name);
		}
		else {
			money -= price;
			printf("%s����!!\n���� �ܾ� : %d��\n", name, money);
		}
	}
}