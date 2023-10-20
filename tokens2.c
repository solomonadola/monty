#include "monty.h"

int unknown_op_err(char *opcode, unsigned int counter);
int no_int(unsigned int counter);
int short_stack_err(unsigned int counter, char *op);
int pop_err(unsigned int counter);
int pchar_error(unsigned int counter, char *message);

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


/**
 * short_stack_err - Prints monty math function error messages.
 * @counter: Line number
 * @op: Operation where the error occurred.
 *
 * Return: EXIT_FAILURE.
 **/
int short_stack_err(unsigned int counter, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", counter, op);
	return (EXIT_FAILURE);
}

/**
 * pchar_err - Prints pchar error messages for empty stacks
 * @counter: Line number
 * @message: The corresponding error message to print.
 *
 * Return: EXIT_FAILURE
 *
 **/

int pchar_err(unsigned int counter, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", counter, message);
	return (EXIT_FAILURE);
}

/**
 * pop_err - Prints pop error messages for empty stacks.
 * @counter: Line number
 *
 * Return: EXIT_FAILURE always.
 *
 **/

int pop_err(unsigned int counter)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", counter);
	return (EXIT_FAILURE);
}
