#include "monty.h"

/**
 * queue - Converts a stack to a queue.
 * @head: A pointer to the stack mode node of a stack_t linked list.
 * @counter: The current working number.
 **/

void queue(stack_t **head, unsigned int counter)
{
	(*head)->n = QUEUE;
	(void)counter;
}
