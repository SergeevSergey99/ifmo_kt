// Homework1_Algorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*
#include <stdio.h>

#define STACK_MAX_SIZE 1000000
#define LEN 10

int stack[STACK_MAX_SIZE];
int i = 0;

void s_push(int n){
	stack[i++] = n;
}

int s_pop(){
	return stack[--i];
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
				s_push(atoi(&cArray[2]));
			if (cArray[0] == '-')
				printf("%i\n", s_pop());

		}
	
		fclose(pTextFile);
	}
	return 1;
}

*/
