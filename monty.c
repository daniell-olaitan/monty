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
	char *cmdl = NULL;
	cmd_t *line;
	FILE *stream;
	void (*instruction)(int arg);

	if (argc != 2)
		print_error("USAGE: monty file\n");

	stream = fopen(argv[1], "r");
	if (stream == NULL)
		print_error("Error: Can't open file ",
			    argv[1], "\n");

	line->opcode = NULL;
	line->number = 0;
	line->args = 0;
	while (getline($cmdl, &len, stream) != -1)
	{
		line = parse_line(cmdl);
		if (line == NULL)
			continue;

		instruction = fetch_instruction(line, op_dic);
		execute(instruction, line);
	}

	free(cmdl);
	fclose(stream);
	return (0);
}
