/*#include <stdio.h>

char stack[10000];
long n = 0;

int main() {

	FILE* pTextFile;
	fopen_s(&pTextFile, "brackets.in", "r");

	char c;

	if (pTextFile != NULL) {

		do
		{
			c = fgetc(pTextFile);
			if (c == '\n' || c == EOF) {
				printf((n == 0) ? "YES\n" : "NO\n");
				continue;
			}

			if (n > 0 && (stack[n - 1] == '(' && c == ')') || (stack[n - 1] == '[' && c == ']') || (stack[n - 1] == '{' && c == '}')) {
				n--;
			}
			else {
				stack[n++] = c;
			}
			
		} while (c != EOF);
	}

	fclose(pTextFile);

	return 1;
}*/