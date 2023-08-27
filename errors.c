#include "monty.h"

/**
 * exit_error - prints exit value on failure
 *
 * Return: void
 */
void exit_error(void)
{
	exit(EXIT_FAILURE);
}

/**
 * usage_error - Prints usage error if program is used wrongly
 *
 * Return: void
 */
void usage_error(void)
{
	if (argc != 2)
	{
		printf(stderr, "USAGE: monty file\n");
	}
}

/**
 * open_error - Display an error message if file cannot be open and exit
 *
 * Return: Nothing
 */
void open_error(void)
{
	fprintf(stderr, "Error: Can't open file <file>\n", argv[1]);
}

/**
 * unknown_error - prints unknown error to stderr if opcode is invalid.
 *
 * Return: returns nothing
 */
void unknown_error(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
}
