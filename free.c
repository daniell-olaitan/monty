#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: ...
 *
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp, *top;

	top = stack;
	while (top != NULL)
	{
		tmp = top->next;
		free(top);
		top = tmp;
	}
}
