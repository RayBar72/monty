#include "monty.h"

arg_t arg = {0, 0};

/**
 * comment_check - checks if line is a comment
 * @line: struct containing line contents and line number
 *
 * Return: true if comment, else false
 */
bool comment_check(line_t line)
{
	if (!line.content[0])
	{
		free(line.content);
		return (true);
	}
	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}
	return (false);
}


/**
 * argument_check - verifies argument is valid
 * @token: the argument to be checked
 *
 * Return: true if valid argument, else false
 */
bool argument_check(char *token)
{
	unsigned int i;

	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
 * push_check - check if push opcode is being used and sets global
 * argument variable if true
 * @line: struct containing line contents and line number
 * @opcode: the opcode to compare
 * @lectura: struct containing all allocated memory
 *
 * Return: Nothing.
 */
void push_check(line_t line, lect_t *lectura, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && !argument_check(line.content[1]))
	{
		free(line.content);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		free(lectura->buf);
		free_stack(&(lectura->stack));
		fclose(lectura->file);
		free(lectura);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		arg.arg = atoi(line.content[1]);
}

/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	else
		return (0);
}
