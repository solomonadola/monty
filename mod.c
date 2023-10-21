#include "monty.h"

/**
 * mod - calcs the mod of the second value from
 * the top of a stack_t linked list by the top value.
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * @counter: The current working number.
 **/

void mod(stack_t **head, unsigned int counter)
{
	if ((*head)->next == NULL || (*head)->next->next == NULL)
	{
		set_op_tok_error(short_stack_err(counter, "mod"));
		return;
	}
	
	if ((*head)->next->n == 0)
	{
		set_op_tok_error(div_err(counter));
		return;
	}
	
	(*head)->next->next->n %= (*head)->next->n;
	pop(head, counter);
}
