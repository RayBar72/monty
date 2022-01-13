#include "monty.h"


/**
 * no_num - error if no number
 * @uno: pointer to token1
 * @dos: pointer to token2
 * @n: line numb
 */

void no_num(char *uno, char *dos, unsigned int n)
{
	fprintf(stderr, "L%d: usage: push integer\n", n);
		free(uno);
		free(dos);
		exit(EXIT_FAILURE);
}
