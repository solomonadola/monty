#include "monty.h"

/**
 * rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * @counter: The current working number.
 **/

void rotl(stack_t **head, unsigned int counter)
{
	stack_t *top, *bottom;
	if ((*head)->next == NULL || (*head)->next->next == NULL)
		return;
	
	top = (*head)->next;
	bottom = (*head)->next;
	
	while (bottom->next != NULL)
		bottom = bottom->next;
	top->next->prev = *head;
	(*head)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;
	
	(void)counter;
}
