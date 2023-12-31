#include "monty.h"

int pint_err(unsigned int counter);
int div_err(unsigned int counter);

/**
 * pint_err - Prints pint error messages for empty stacks.
 * @counter: Line number
 *
 * Return: EXIT_FAILURE
 *
 **/

int pint_err(unsigned int counter)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
	return (EXIT_FAILURE);
}

/**
 * div_err - prints divide error messages
 * @counter: line number
 *
 * Return: EXIT FAILURE
 *
 */

int div_err(unsigned int counter)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", counter);
	return (EXIT_FAILURE);
}
