#include<stdio.h>
#include<string.h>
//사용자 정의 헤더파일 추가
#include"twosomeplace.h"
//상품 최대갯수
#define CNT 100

/*전역 변수*/
//상품명 배열
char arName[CNT][100] = { "", };
//가격 배열
int arPrice[CNT] = { 0, };
//추가된 상품 총 갯수
int insertCnt = 0;
//검색된 상품의 행번호
int rowNum;


void main() {
	//twosomeplace.h 참고
	cafe();
}







