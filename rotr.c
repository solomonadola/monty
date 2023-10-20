#include "monty.h"

/**
 * rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * @counter: The current working number.
 **/

void rotr(stack_t **head, unsigned int counter)
{
	stack_t *top, *bottom;
	
	if ((*head)->next == NULL || (*head)->next->next == NULL)
		return;
	
	top = (*head)->next;
	bottom = (*head)->next;
	
	while (bottom->next != NULL)
		bottom = bottom->next;
	bottom->prev->next = NULL;
	(*head)->next = bottom;
	bottom->prev = *head;
	bottom->next = top;
	top->prev = bottom;
	
	(void)counter;
}
