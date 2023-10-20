#include "monty.h"
#include <string.h>

int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);

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
		{"pall", pall},
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
