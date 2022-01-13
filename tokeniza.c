#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * tokens_line - functinon that parses a string into tokens
 * @line: struck
 * @buf: string from getline
 */

void tokens_line(line_t *line, char *buf)
{
	char *token = NULL;
	unsigned int i = 0;

	line->content = malloc(sizeof(char *) * 3);
	if (!line->content)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(buf, "\t\n ");
	for (i = 0; token && i < 2; i++)
	{
		line->content[i] = token;
		token = strtok(NULL, "\t\n ");
	}

	line->content[i] = NULL;
}

/**
 * tokens - functinon that parses a string into tokens
 * @fp: string to be parsed
 */

void tokens(FILE *fp)
{
	lect_t *lectura = NULL;
	line_t line;
	size_t size = 0;

	lectura = malloc(sizeof(lect_t));
	if (!lectura)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	line.number = 0;
	line.content = NULL;
	lectura->file = fp;
	lectura->stack = NULL;
	lectura->buf = NULL;

	while (getline(&(lectura->buf), &size, lectura->file) != -1)
	{
		line.number++;
		tokens_line(&line, lectura->buf);
		if (line.content)
			pichi(line, lectura)(&(lectura->stack), line.number);
	}
	free(lectura->buf);
	free_stack(&(lectura->stack));
	fclose(lectura->file);
	free(lectura);
}
