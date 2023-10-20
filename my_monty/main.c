#include "monty.h"

char **tok = NULL;

/**
 * main - the entry point
 *
 * @argc: argument count
 * @argv: array pointer
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 **/

int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;
	
	if (argc != 2)
		return (usage_err());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (open_err(argv[1]));
	exit_code = run(script_fd);
	fclose(script_fd);
	return (exit_code);
}
