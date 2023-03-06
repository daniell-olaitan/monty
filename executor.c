#include "monty.h"

/**
 * execute - fetches instruction for the opcode
 * @cmdl: command line
 *
 */
void execute(cmd_t *cmdl)
{
	int i, len;
	char str[1024];
	instruction_t opcodes[] = {
		{"push", push},
		//{"pop", pop},
	};

	len = sizeof(opcodes);
	for (i = 0; i < len; ++i)
	{
		if (opcodes[i].opcode == cmdl->opcode)
		{
			opcodes[i].f(&stack, (unsigned int)cmdl->number);
			return;
		}
	}

	print_error(5, "L", sprintf(str, "%d", (int)cmdl->number),
		    ": unknown instruction",
		    cmdl->opcode, "\n");
}
