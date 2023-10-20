#include "monty.h"

/**
 * monty_pop - Removes the top element of a stack_t linked list.
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * @counter: The current working number
 **/

void pop(stack_t **head, unsigned int counter)
{
	stack_t *next = NULL;
	
	if ((*head)->next == NULL)
	{
		set_op_tok_error(pop_err(counter));
		return;
	}
	
	next = (*head)->next->next;
	free((*head)->next);
	if (next)
		next->prev = *head;
	(*head)->next = next;
}
