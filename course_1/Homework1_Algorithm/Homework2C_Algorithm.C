#include <stdio.h>

#define QUE_MAX_SIZE 1000000
#define LEN 10

int stack[QUE_MAX_SIZE];
int i = 0;
int j = 0;

void q_push(int n) {
	stack[j++] = n;
}

int q_pop() {
	return stack[i++];
}

int main() {


	FILE* pTextFile;
	fopen_s(&pTextFile, "stack1.in", "r");

	char cArray[LEN];

	if (pTextFile != NULL) {


		fgets(cArray, LEN, pTextFile);
		int n = atoi(cArray);
		int i = 0;
		while (n > i && fgets(cArray, LEN, pTextFile) != NULL)
		{
			i++;

			if (cArray[0] == '+')
				q_push(atoi(&cArray[2]));
			if (cArray[0] == '-')
				printf("%i\n", q_pop());

		}
	
	fclose(pTextFile);
	}

	return 1;
}
