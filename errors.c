#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1024

int malloc_err(void);
int check_mode(stack_t *stack);
int usage_err(void);
int open_err(char *filename);
int run(FILE *script_fd);

/**
 * malloc_err - prints malloc's error message
 *
 * Return: Exit Failure
 */

int malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * check_mode - confirms the mode of a stack_t linked list (stack or queue)
 * @stack: a pointer to the top or bottom
 * Return: if in stack mode; STACK (0)
 * if in queue mode; QUEUE (1). else, -2
 */

int check_mode (stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

/**
 * usage_err - prints usage error message
 *
 * Return: EXIT_FAILURE
 */

int usage_err(void)
{
	fprintf(stderr, "USAGE: monty failed\n");
	return (EXIT_FAILURE);
}

/**
 * open_err - prints errors from file opening
 * @filename: name of file opened
 *
 * Return: EXIT_FAILURE
 */

int open_err(char *filename)
{
	fprintf(stderr, "Error: can't open file %s\n", filename);
	return (EXIT_FAILURE);
}



/**
 * run - function to execute monty bycodes script
 * @script_fd: file descriptor
 *
 * retur: EXIT_SUCCESS on success, error on failure
 */

int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = MAX_LINE_LENGTH, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);
	char **op_toks;

	line = malloc(len * sizeof(char));
	if (line == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (EXIT_FAILURE);
	}
	
	if (init(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (fgets(line, MAX_LINE_LENGTH, script_fd) != NULL)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_err());
		}
		else if (op_toks[0][0] == '#')
		{
			tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_err(op_toks[0], line_number);
			tokens();
			break;
		}
		
		prev_tok_len = token_arr();
		op_func(&stack, line_number);
		
		if (token_arr() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			tokens();
			break;
		}
		
		tokens();
	}
	free_stack(&stack);
	
	if (line && *line == 0)
	{
		free(line);
		return (malloc_err());
	}
	free(line);
	return (exit_status);
}
