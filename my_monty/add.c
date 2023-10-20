#include "monty.h"

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * @counter: The current working number
 */

void add(stack_t **head, unsigned int counter)
{
	if ((*head)->next == NULL || (*head)->next->next == NULL)
	{
		set_op_tok_error(short_stack_err(counter, "add"));
		return;
	}
	(*head)->next->next->n += (*head)->next->n;
	pop(head, counter);
}
