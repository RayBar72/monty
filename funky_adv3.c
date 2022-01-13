#include "monty.h"

/**
 * fun_rotl - rotates top
 * @stack: p-t-p
 * @nline: line number
 */
void fun_rotl(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	int hold_this, hold_this_again;
	(void)nline;

	if (stack == NULL || *stack == NULL)
	{
		fun_nop(stack, nline);
	}

	hold_this = (*stack)->n;
	temp = *stack;

	while (temp)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}

	hold_this_again = temp->n;
	(*stack)->n = hold_this_again;
	temp->n = hold_this;
}

/**
 * fun_rotlop - rotates to left
 * @stack: p-t-p
 * @nline: line number
 */
void fun_rotlop(stack_t **stack, unsigned int nline)
{
	stack_t *last, *tmp;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	tmp = *stack;
	last = tmp;

	while (last->next)
	{
		last = last->next;
	}

	last->next = tmp;
	tmp->prev = last;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	tmp->next = NULL;
}

/**
 * fun_rotrop - rotates to right
 * @stack: p-t-p
 * @nline: line number
 */
void fun_rotrop(stack_t **stack, unsigned int nline)
{
	stack_t *last, *tmp;

	(void)nline;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	tmp = *stack;
	last = tmp;

	while (last->next)
	{
		last = last->next;
	}

	last->prev->next = NULL;
	last->prev = NULL;
	tmp->prev = last;
	last->next = tmp;
	*stack = last;
}

/**
 * fun_qpush - pushes for queue instead of stack
 * @stack: p-t-p
 * @nline: line number
 */
void fun_qpush(stack_t **stack, unsigned int nline)
{
	stack_t *last, *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	last = NULL;
	if (*stack)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
