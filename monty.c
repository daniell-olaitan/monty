#include "monty.h"

int argument = 0;
bool valid = false;
stack_t *stack = NULL;

/**
 * main - starting point of the monty program
 * @argc: number of cmd args
 * @argv: pointer to arg vector
 *
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	char *line = NULL;
	cmd_t *cmdl;
	FILE *stream;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	cmdl = malloc(sizeof(cmd_t));
	if (cmdl == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	cmdl->opcode = NULL;
	cmdl->number = 0;
	while ((getline(&line, &len, stream)) != -1)
	{
		parse_line(&cmdl, line);
		if (cmdl->opcode == NULL)
			continue;

		execute(cmdl);
	}

	free(line);
	free_stack(stack);
	fclose(stream);
	return (0);
}
