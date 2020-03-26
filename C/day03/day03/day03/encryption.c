#include<stdio.h>

void main() {
	char pw[7] = "a1b2c3";
	char en_pw[7] = "";

	for (int i = 0; i < 7; i++) {
		en_pw[i] = (char)(pw[i] * 3);
	}
}