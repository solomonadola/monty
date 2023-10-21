#include "monty.h"
#include <string.h>

int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
void free_stack(stack_t **stack);
int init(stack_t **stack);
void tokens(void);

/**
 * is_empty_line - checks if a line from getline only has delimiters
 * @line: pointer to line
 * @delims: string of delimiters
 * Return: If the line only contains delimiters - 1.
 * Otherwise - 0.
 **/
int is_empty_line(char *line, char *delims)
{
	int w, v;
	
	for (w = 0; line[w]; w++)
	{
		for (v = 0; delims[v]; v++)
		{
			if (line[w] == delims[v])
				break;
		}
		if (delims[v] == '\0')
			return (0);
	}
	return (1);
}



/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 **/

void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", f_pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	
	int i;
	
	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 **/

void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;
	
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}


/**
 * init - Initializes a stack_t stack with beginning
 * stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 * Otherwise - EXIT_SUCCESS.
 **/

int init(stack_t **stack)
{
	stack_t *i;
	
	i = malloc(sizeof(stack_t));
	
	if (i == NULL)
		return (malloc_err());
	i->n = STACK;
	i->prev = NULL;
	i->next = NULL;
	*stack = i;
	
	return (EXIT_SUCCESS);
}

/**
 * tokens - Frees the global tok array of strings.
 *
 **/

void tokens(void)
{
	size_t d = 0;
	
	if (tok == NULL)
		return;
	for (d = 0; tok[d]; d++)
		free(tok[d]);
	free(tok);
}
