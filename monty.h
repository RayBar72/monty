#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line - contents of line and corresponding number
 * @content: array of tokens read from the line
 * @number: the line number
 *
 * Description: contents of a line and corresponding number
 */
typedef struct line
{
	unsigned int number;
	char **content;
} line_t;

/**
 * struct lectura - contents of line and corresponding number
 * @file: array type file
 * @buf: buffer for get line
 * @stack: pointer struck for stack
 *
 * Description: contents of a line and corresponding number
 */
typedef struct lectura
{
	FILE *file;
	char *buf;
	stack_t *stack;
} lect_t;

/**
 * args_s - struck for, in case, arguments of funct
 * @arg: number
 * @flag: boolean
 * Description: for checker of arguments
 */

typedef struct arg_s
{
	int arg;
	int flag;
} arg_t;

extern arg_t arg;

/* funciones de error*/
void no_num(char *uno, char *dos, unsigned int n);

/*funciones de lectura*/
void tokens(FILE *fp);
void (*pichi(line_t line, lect_t *lectura))(stack_t **, unsigned int);

/*funciones de trabajo*/
void fun_push(stack_t **stack, unsigned int nline);
void fun_pall(stack_t **stack, unsigned int nline);
void fun_pint(stack_t **stack, unsigned int nline);
void fun_pop(stack_t **stack, unsigned int nline);
void fun_swap(stack_t **stack, unsigned int nline);
void fun_addop(stack_t **stack, unsigned int nline);
void fun_nop(stack_t **stack, unsigned int nline);
void fun_subop(stack_t **stack, unsigned int nline);
void fun_divop(stack_t **stack, unsigned int nline);
void fun_mulop(stack_t **stack, unsigned int nline);
void fun_modop(stack_t **stack, unsigned int nline);
void fun_qpush(stack_t **stack, unsigned int nline);
void fun_pchar(stack_t **stack, unsigned int nline);
void fun_pstr(stack_t **stack, unsigned int nline);
void fun_rotrop(stack_t **stack, unsigned int nline);
void fun_rotlop(stack_t **stack, unsigned int nline);
void fun_addst(stack_t **stack, unsigned int nline);
void fun_addqu(stack_t **stack, unsigned int nline);

/*funciones de liberacion y check*/
void free_stack(stack_t **stack);
void push_check(line_t line, lect_t *lectura, char *opcode);
bool comment_check(line_t line);
int _isalpha(int c);

#endif
