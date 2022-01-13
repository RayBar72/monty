#include "monty.h"




int main(int argc, char **argv)
{

	FILE *fp;
	char *recorre = NULL;
	size_t size = 0;
	int count1 = 0, count2 = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE:monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&recorre, &size, fp) != -1)
	{
		count1++;
		if (!strcmp(recorre, "\n"))
			count2++;
	}
	free(recorre);
	if (count1 == count2)
	{
		fclose(fp);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	fp = fopen(argv[1], "r");
	tokens(fp);

	return (0);
}
