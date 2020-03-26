#include<stdio.h>
#include<stdlib.h>
/*
	학생 구조체 선언(typedef)
	*요소
	학생 이름, 나이, 국, 영, 수 점수
	학생 정보 입력은 함수로 선언(void형)
	총 학생 수는 입력받는다.
	동적 배열로 학생 구조체 배열 선언 후 학생 별 총점, 평균 출력
*/

//과목명에 규칙성 부여
char* arSub[3] = { "국어","영어","수학" };

typedef struct Student {
	char name[30];
	int age;
	//3칸 정수 배열
	int arScore[3];
}tag_Student;

//구조체 주소를 전달받아서 직접 접근하여 초기화 해준다.
void inputInfo(tag_Student* member) {
	
	printf("학생 이름 :");
	//멤버 변수에 접근할 때 2번 참조할 때에는 ->(화살표 연산자)를 사용한다.
	scanf_s("%s", member->name, sizeof(member->name));
	printf("학생 나이 :");
	scanf_s("%d", &member->age);
	//과목이 3개이므로 3번 반복한다.
	for (int i = 0; i < 3; i++) {
		printf("%s 점수", arSub[i]);
		scanf_s("%d", member->arScore + i);
	}
}



void main() {
	int cnt = 0;
	int total = 0;
	double avg = 0.0;
	printf("학생 수 : ");
	scanf_s("%d", &cnt);
	//동적할당
	tag_Student* arStudent = (tag_Student*)malloc(sizeof(tag_Student)*cnt);

	//학생 수만큼 반복하여 각 구조체의 주소값을 inputInfo함수에 전달한다.
	for (int i = 0; i < cnt; i++) {
		inputInfo(arStudent+i);
	}
	for (int i = 0; i < cnt; i++) {
		//이전 학생의 총점 초기화
		total = 0;
		//[], .두번 접근하므로 포인터 연산과 -> 연산자로 접근할 수 있다.
		printf("%s 학생", (arStudent+i)->name);
		for (int j = 0; j < 3; j++) {
			printf("%s : %d점", arSub[j], (arStudent + i)->arScore[j]);
			total += (arStudent + i)->arScore[j];
		}
		avg = (double)total / 3;
		printf("총점 : %d점", total);
		printf("평균 : %2lf점", avg);
	}
	

}




