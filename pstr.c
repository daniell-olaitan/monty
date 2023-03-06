#include "monty.h"

/**
 * _pstr - prints the string starting from the top of the stack
 * @stack:...
 * @line_number:...
 *
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (stack == NULL)
		return;

	while (tmp != NULL || (tmp->n > 0 || tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
}
