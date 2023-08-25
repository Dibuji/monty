#include "monty"

/**
 * pall - print all opcodes
 * @stack: pointer to pointer to stack
 * @line_number: number of the line opcode occurs on
 */
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
stack_t *runner;
runner = *stack;
while (runner != NULL)
{
printf("%d\n", runner->n);
runner = runner->next;
}
}
