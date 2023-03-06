#include "monty.h"

/**
 * _pop - removes the top of the stack
 * @stack:...
 * @line_number:...
 *
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	free(tmp);
}
