#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - function to add an element to a stack
 * @stack: the stack to be added to
 * @line_number: the line number
 * @n: the value to add on the stack
 */

void push(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *new;
	int numb;

	(void) line_number;

	if (*stack == NULL)
		return;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (n == NULL || !isInteger(n))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	numb = atoi(n);

	new->n = numb;
	new->prev = NULL;

	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	else
		new->next = NULL;
	*stack = new;
}

/**
 * pall - prints all values on the stack
 * @stack: stack to be printed from
 * @line_number: the line number
 * @n: data
 */

void pall(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *top;

	(void)line_number;
	(void)n;

	if (*stack == NULL)
		return;

	top = *stack;
	while (top != NULL)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * pop - function to delete element from a stack
 * @stack: stack to be deleted from
 * @line_number: line number
 * @n: data
 */


void pop(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *top;

	(void)n;

	if (*stack == NULL)
    {
		fprintf(stderr, "L%d: Error: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free_stack(&top);
}

/**
 * pint - function to print value at top of stack
 * @stack: pointer to stack pointer
 * @line_number: line number
 * @n: data
 */

void pint(stack_t **stack, unsigned int line_number, char *n)
{
	(void)n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
