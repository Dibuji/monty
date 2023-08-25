#ifndef MONTY_H
#define MONTY_H

#define LIMIT 1024

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Structures Definitions ---*/
extern int push_arg;

/**
 * struct stack_s - stack/queue doubly linked list implementation structure
 * @n: integer
 * @prev: pointer to previous element of the stack (or queue)
 * @next: pointer to next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 *    for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 *   for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - struct for opcoode and its function
 * @file: the opcode
 * @push_arg: Handles the opcode
 * @buffer: buffer pointer
 *
 * Description: opcode and its function
 *   for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_variable
{
    FILE *file;
    int push_arg;
    char *buffer;
} global_var;

extern global_var var_global;

/**
 * struct token_s - data structure for the token
 * @command: the argument the user passes
 * @hasValue: flag that shows when value is present
 * @value: the value associated with the argument
 */

typedef struct token_s
{
	char command[256];
	int hasValue;
	int value;
} token_t;


void push(stack **stack, __attribute__((unused))unsigned int line_number);
token_t tokenizer(char *str);

#endif
