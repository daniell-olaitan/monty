#include "monty.h"

/**
 * parse_line - parses the command line read from a monty file
 * @cmdl: the read command line
 * @line: result of passed line
 *
 */
void parse_line(cmd_t **cmdl, char *line)
{
	char *tmp, *arg, *endptr, *delim = " \n";

	(*cmdl)->number++;
	if (line[0] == '#')
	{
		(*cmdl)->opcode = NULL;
		return;
	}

	tmp = strtok(line, "#");
	(*cmdl)->opcode = strtok(tmp, delim);
	if ((*cmdl)->opcode == NULL)
		return;

	arg = strtok(NULL, delim);
	if (arg != NULL)
	{
		argument = (int)strtol(arg, &endptr, 10);
		if (*endptr != '\0')
			valid = false;

		else
			valid = true;
	}
	else
		valid = false;
}
