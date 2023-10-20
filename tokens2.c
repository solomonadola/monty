#include "monty.h"

int unknown_op_err(char *opcode, unsigned int counter);
int no_int(unsigned int counter);

/**
 * unknown_op_err - Prints unknown instruction error message.
 * @opcode: Opcode where the error occurred.
 * @counter: Line number.
 *
 * Return: EXIT_FAILURE.
 **/
int unknown_op_err(char *opcode, unsigned int counter)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			counter, opcode);
	return (EXIT_FAILURE);
}


/**
 * no_int - Prints invalid argument error message.
 * @counter: Line number
 *
 * Return: EXIT_FAILURE.
 *
 **/
int no_int(unsigned int counter)
{
	    fprintf(stderr, "L%u: usage: push integer\n", counter);
	        return (EXIT_FAILURE);
}
