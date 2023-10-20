#include "monty.h"

/**
 * stack - Converts a queue to a stack.
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * @counter: The current working number.
 **/

void stack(stack_t **head, unsigned int counter)
{
	(*head)->n = STACK;
	(void)counter;
}
