#include "monty.h"

/**
 * fun_addst - changes from push to stack
 * @stack: p-t-p
 * @nline: line number
 */
void fun_addst(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 0;
}

/**
 * fun_addqu - changes mode from push to queue
 * @stack: p-t-p
 * @nline: line number
 */
void fun_addqu(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 1;
}
