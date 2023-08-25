#include <monty.h>

/**
 * main - Entry point for the program
 * @argc: Number of arguments
 * @argv: Arguments passed
 * Return: (0) on success, (1) on failure.
 */

int main(int argc, char **argv)
{
	token_t token;
	char str[1024];
	instruction_t *instructions;
	int compared;

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
	token = tokenizer(str);
	instructions = get_instructions();


	compared = compare(token, instructions);

	fclose(input);
	return(0);
}
