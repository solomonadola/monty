#include "monty.h"

/**
 * push - opcode to push an element to the stack
 * @head: Begining of the stack
 * @counter: number
 * Return: void
 */

void push(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int m;
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		set_op_tok_error(malloc_err());
		exit(EXIT_FAILURE);
		return;
	}
	
	if (tok[1] == NULL)
	{
		set_op_tok_error(no_int(counter));
		return;
	}
	
	for (m = 0; tok[1][m]; m++)
	{
		if (tok[1][m] == '-' && m == 0)
			continue;
		if (tok[1][m] < 48 || tok[1][m] > 57)
		{
			set_op_tok_error(no_int(counter));
			return;
		}
	}

	node->n = atoi(tok[1]);
	
	if (check_mode(*head) == STACK)
	{
		tmp = (*head)->next;
		node->prev = *head;
		node->next = tmp;
		
		if (tmp)
			tmp->prev = node;
		(*head)->next = node;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		node->prev = tmp;
		node->next = NULL;
		tmp->next = node;
	}
}

/**
 * f_pall - prints all the values on the stack
 * @head: begining of the stack
 * @counter: number
 * Return: NULL
 **/

void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *m;
	(void)counter;
	m = *head;
	
	if (m == NULL)
		return;
	while (m)
	{
		printf("%d\n", m->n);
		m = m->next;
	}
}
