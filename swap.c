#include "monty.h"

/**
 * swap - swaps two top elements of the stack
 * @stack:...
 * @line_number:...
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL ||
	    *stack == NULL ||
	    (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = (*stack)->prev;
	tmp->next = *stack;
	*stack = tmp;
}
