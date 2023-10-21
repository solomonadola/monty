#include "monty.h"

/**
 * pchar - Prints the character in the top value node of a stack_t linked list.
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * @counter: The current working number.
 **/

void pchar(stack_t **head, unsigned int counter)
{
	if ((*head)->next == NULL)
	{
		set_op_tok_error(pchar_err(counter, "stack empty"));
		return;
	}
	
	if ((*head)->next->n < 0 || (*head)->next->n > 127)
	{
		set_op_tok_error(pchar_err(counter, "value out of range"));
		return;
	}
	
	printf("%c\n", (*head)->next->n);
}
