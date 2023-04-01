#include <cstdio>
#include <cstdlib>

void getNum(int* S) {
	int res = 1;
	do {
		int code = scanf_s("%d", S);
		res = code;
		char temp;
		while ((temp = getchar()) != '\n') {
			if ((temp > '9') || (temp < '0')) {
				res = -2;
				break;
			}
		}
		rewind(stdin);
	} while (res != 1);
}

void getFloat(float* S) {
	int res = 1;
	do {
		int code = scanf_s("%f", S);
		res = code;
		char temp;
		while ((temp = getchar()) != '\n') {
			if ((temp > '9') || (temp < '0') || (temp != '.')) {
				res = -2;
				break;
			}
		}
		rewind(stdin);
	} while (res != 1);
}