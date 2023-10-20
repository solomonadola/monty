#include "monty.h"

/**
 * swap - Swaps the top two value elements of a stack_t linked list.
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * @counter: The current working number.
 **/

void swap(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	
	if ((*head)->next == NULL || (*head)->next->next == NULL)
	{
		set_op_tok_error(short_stack_err(counter, "swap"));
		return;
	}
	temp = (*head)->next->next;
	(*head)->next->next = temp->next;
	(*head)->next->prev = temp;
	
	if (temp->next)
		temp->next->prev = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next = temp;
}
