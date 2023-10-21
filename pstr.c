#include "monty.h"

/**
 * pstr - Prints the string contained in a stack_t linked list.
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * @counter: The current working number.
 **/

void pstr(stack_t **head, unsigned int counter)
{
	stack_t *temp = (*head)->next;
	
	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void)counter;
}
