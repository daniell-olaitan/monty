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
	cmd_t *cmd = *cmdl;

	cmd->number++;
	if (line[0] == '#')
	{
		cmd->opcode = NULL;
		return;
	}

	tmp = strtok(line, "#");
	cmd->opcode = strtok(tmp, delim);
	if (cmd->opcode == NULL)
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
