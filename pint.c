#include "monty.h"

/**
 * pint - prints the top of the stack
 * @stack:...
 * @line_number: ...
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
