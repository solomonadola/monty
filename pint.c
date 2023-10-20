#include "monty.h"

/**
 * pint - prints the top value in a stack_t linked list
 * @head: pointer to the stack mode node
 * @counter: current line number
 *
 * Return: void
 */

void pint(stack_t **head, unsigned int counter)
{
	if ((*head)->next == NULL)
	{
		set_op_tok_error(pint_err(counter));
		return;
	}
	printf("%d\n", (*head)->next->n);
}

