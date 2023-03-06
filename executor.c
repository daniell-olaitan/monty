#include "monty.h"

/**
 * execute - fetches instruction for the opcode
 * @cmdl: command line
 *
 */
void execute(cmd_t *cmdl)
{
	int i, len;
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"add", _add},
		{"mul", _mul},
		{"swap", _swap},
		{"div", _div},
		{"sub", _sub},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr}
	};

	len = sizeof(opcodes) / sizeof(instruction_t);
	for (i = 0; i < len; ++i)
	{
		if (strcmp(opcodes[i].opcode, cmdl->opcode) == 0)
		{
			opcodes[i].f(&stack, (unsigned int)cmdl->number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", (int)cmdl->number,
		cmdl->opcode);
	exit(EXIT_FAILURE);
}
