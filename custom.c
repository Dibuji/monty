#include "monty.h"

/**
 * tokenizer - function to return bytecode command and value
 * @str: line read from file
 * Return: the token
 */

token_t tokenizer(char *str)
{
	char *command, *value;
	token_t token;

	token.hasValue = 0;

	command = strtok(str, " ");
	token.command = strdup(command);

	value = strtok(NULL, " ");
	if (value != NULL)
	{
		token.value = atoi(value);
		token.hasValue = 1;
	}

	return (token);
}

/**
 * get_instructions - function to get instructions
 * Return: instructions
 */

instruction_t *get_instructions(void)
{
	static instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{NULL, NULL},
	};

	return (instructions);
}

/**
 * compare - Function to compare user file input with set instructions
 * @token: From user file
 * @instruction: The array of instructions
 * Return: Nothing
 */

void compare(token_t token, instruction_t *instructions)
{
	size_t i;
	int compared = 1;

	for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
	{
		compared = strcmp(instructions[i].opcode, token.command);
		if (compared == 0)
		{
			instructions[i].f(value);
			exit(EXIT_SUCCESS);
		}
	}

	unknown_error();
	exit_error();
}
