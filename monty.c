#include <monty.h>

/**
 * main - Entry point for the program
 * @argc: Number of arguments
 * @argv: Arguments passed
 * Return: (0) on success, (1) on failure.
 */

int main(int argc, char **argv)
{
	char str[LIMIT];

	if (argc != 2)
	{
		usage_error();
		exit_error();
	}

	input = fopen(argv[1], "r");
	if (input == NULL)
	{
		open_error();
		exit_error();
	}

	fgets(str, sizeof(str), input);
    _compile(str);

	token = tokenize(str);
	compared = strcmp(opcode, token);
	if (compared = 0)
	{
		call_function(token, value);
	}
	else if (compared != 0)
	{
		unknown_error();
		exit_error();
	}

	fclose(input);
	return(0);
}
