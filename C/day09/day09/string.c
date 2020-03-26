#include<stdio.h>
void main() {
	//const char nation[6] = "korea";
	char nation[6] = "korea";


	//접근해서 수정하는 것을 막아준다.
	//따라서 scanf_s()로 입력받을 수 없다.
	const char* natin2 = "japan";


	//포인터자료형 앞에 const는 참조상수
	//포인터명 앞에 const는 상수 -> 주소값을 변경할 수 없다.
	const char* const nation3 = "china";
		
	printf("%s\n", nation);
	
	nation2 = "korea";
	nation3 = "korea";
	//nation = "japan";


}