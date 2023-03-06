#include "monty.h"

/**
 * _pall - prints all the elements in the stack
 * @stack: ...
 * @line_number: line number of the command
 *
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
