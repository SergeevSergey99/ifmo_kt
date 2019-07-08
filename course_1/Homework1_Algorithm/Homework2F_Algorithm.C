#include <stdio.h>

int stack[100];
long n = 0;

int main() {

	FILE* pTextFile;
	fopen_s(&pTextFile, "postfix.in", "r");

	char c;

	while ((c = fgetc(pTextFile)) != EOF) {
		if (c == ' ') {
			continue;
		}

		if (c < '0' || c > '9') {
			switch (c) {
			case '+':
				stack[n - 2] = stack[n - 2] + stack[n - 1];
				n--;
				break;

			case '-':
				stack[n - 2] = stack[n - 2] - stack[n - 1];
				n--;
				break;

			case '*':
				stack[n - 2] = stack[n - 2] * stack[n - 1];
				n--;
				break;

			case '/':
				stack[n - 2] = stack[n - 2] / stack[n - 1];
				n--;
				break;
			}
		}
		else {
			stack[n++] = c - '0';
		}
	}

	printf("%i", stack[0]);

	fclose(pTextFile);

	return 1;
}
