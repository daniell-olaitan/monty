#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: ...
 *
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp, *top;

	tmp = stack;
	top = tmp;
	while (tmp != NULL)
	{
		tmp = top->next;
		free(top);
		top = tmp;
	}
}
