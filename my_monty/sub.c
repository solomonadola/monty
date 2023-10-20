#include "monty.h"

/**
 * sub - Subtracts the second value from the top
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * counter: The current working number.
 **/

void sub(stack_t **head, unsigned int counter)
{
	if ((*head)->next == NULL || (*head)->next->next == NULL)
	{
		set_op_tok_error(short_stack_err(counter, "sub"));
		return;
	}
	(*head)->next->next->n -= (*head)->next->n;
	pop(head, counter);
}
