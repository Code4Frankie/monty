#include "monty.h"

/**
 * main - Entry point of program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 Always
 */

int main(int argc, char **argv)
{
	char *opcode;
	FILE *the_file;
	size_t len_line = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	char *line = NULL;

	status = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	the_file = fopen(argv[1], "r");

	if (the_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len_line, the_file) != -1)
	{
		if (status == -1)
			break;
		opcode = strtok(line, " \t\n");
		perform_instructs(opcode, line_number, &stack);
		line_number++;
		free(line);
		line = NULL;
	}

	if (line != NULL)
		free(line);
	_freestack(&stack);
	fclose(the_file);
	if (status == -1)
		exit(EXIT_FAILURE);
	return (0);
}
