#include "monty.h"

/**
 * pichi - struct that selects function
 * @line: line number
 * @lectura: pointer to mem alloc
 * Return: void
 */

void (*pichi(line_t line, lect_t *lectura))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", fun_push},
		{"pall", fun_pall},
		{"pint", fun_pint},
		{"pop", fun_pop},
		{"swap", fun_swap},
		{"add", fun_addop},
		{"nop", fun_nop},
		{"sub", fun_subop},
		{"div", fun_divop},
		{"mul", fun_mulop},
		{"mod", fun_modop},
		{"pchar", fun_pchar},
		{"pstr", fun_pstr},
		{"rotl", fun_rotlop},
		{"rotr", fun_rotrop},
		{"stack", fun_addst},
		{"queue", fun_addqu},
		{NULL, NULL}
	};
	unsigned int i = 0;

	if (comment_check(line))
		return (fun_nop);

	while (ops[i].opcode)
	{
		if (!strcmp(ops[i].opcode, line.content[0]))
		{
			push_check(line, lectura, ops[i].opcode);
			if (arg.flag == 1 && strcmp(ops[i].opcode, "push") == 0)
			{
				if (line.content)
					free(line.content);
				return (fun_qpush);
			}
			free(line.content);
			return (ops[i].f);
		}

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line.number,
		line.content[0]);
	free(line.content);
	free(lectura->buf);
	free_stack(&(lectura->stack));
	fclose(lectura->file);
	free(lectura);
	exit(EXIT_FAILURE);
}
