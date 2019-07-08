#include <stdio.h>

typedef struct Node_tag {
	int value;
	struct Node_tag* next;


} Node_t;
Node_t* tail;


void push(Node_t** head, int value) {
	Node_t* tmp = malloc(sizeof(Node_t));
	tmp->value = value;
	tmp->next = NULL;
	if (*head != NULL){

		tail->next = tmp;
	}
	else { 
		tail = tmp;
		*head = tmp;
	}
}


Node_t* pop(Node_t **head) {
	Node_t *tmp = *head;

	*head = (*head)->next;

	return tmp;
}

int main (void){
	Node_t *head = NULL;
	
	FILE* pTextFile;
	fopen_s(&pTextFile, "stack1.in", "r");

	char cArray[10];

	if (pTextFile != NULL) {

		fgets(cArray, 10, pTextFile);
		int n = atoi(cArray);
		int i = 0;
		while (n > i && fgets(cArray, 10, pTextFile) != NULL)
		{
			i++;

			if (cArray[0] == '+')
				push(&head, atoi(&cArray[2]));
			if (cArray[0] == '-')
				printf("%i\n", pop(&head)->value);

		}


		fclose(pTextFile);
	}
	return 1;
}
