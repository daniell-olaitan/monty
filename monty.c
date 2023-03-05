#include "monty.h"

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
	stack_t *stack = NULL;

	if (argc != 2)
		print_error(1, "USAGE: monty file\n");

	stream = fopen(argv[1], "r");
	if (stream == NULL)
		print_error(3, "Error: Can't open file ",
			    argv[1], "\n");

	cmdl = malloc(sizeof(cmd_t));
	if (cmdl == NULL)
		print_error(1, "Error: malloc failed\n");

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
	fclose(stream);
	return (0);
}
