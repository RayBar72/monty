#include "monty.h"

/**
 * fun_addop - adds two elements from the top
 * @stack: p-t-p head
 * @nline: line number
 */
void fun_addop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * fun_nop - nothing
 * @stack: p-t-p head
 * @nline: line number
 * Return: Nothing.
 */
void fun_nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}
