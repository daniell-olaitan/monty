#include "monty.h"

/**
 * execute - fetches instruction for the opcode
 * @cmdl: command line
 *
 */
void execute(cmd_t *cmdl)
{
	int i;
	char str[1024];
	instruction_t opcodes[] = {
		{"push", push},
		{"pop", pop},
		NULL
	};

	for (i = 0; opcodes[i] != NULL; ++i)
	{
		if (opcodes[i].opcode == cmdl->opcode)
		{
			opcodes[i].f(&stack, (unsigned int)cmdl->number);
			return;
		}
	}

	print_error(5, "L", itoa(cmdl->number, str, 10),
		    ": unknown instruction",
		    cmdl->opcode, "\n");
}
