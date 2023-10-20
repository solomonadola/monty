#include "monty.h"

/**
 * set_op_tok_error - Makes the last element of tok an error code
 * @error_code: Integer to store as a string in tok.
 **/

void set_op_tok_error(int error_code)
{
	int len = 0, v = 0;
	char *exit_str = NULL;
	char **new_tok = NULL;
	
	len = token_arr();
	
	new_tok = malloc(sizeof(char *) * (len + 2));
	if (!tok)
	{
		malloc_err();
		return;
	}

	while (v < len)
	{
		new_tok[v] = tok[v];
		v++;
	}
	exit_str = g_int(error_code);
	
	if (!exit_str)
	{
		free(new_tok);
		malloc_err();
		return;
	}
	new_tok[v++] = exit_str;
	new_tok[v] = NULL;
	free(tok);
	tok = new_tok;
}
