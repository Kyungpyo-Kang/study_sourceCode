#include<stdio.h>
#include"f.h"



void main() {
	function();
	//f.h파일에 data가 선언되어 있고
	//위에서 읽고 오기 때문에 data를 사용할 수 있다.
	printf("%d\n", data);
}