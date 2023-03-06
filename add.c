#include "monty.h"

/**
 * add - adds two top elements of the stack
 * @stack:...
 * @line_number:...
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *result;

	if (stack == NULL ||
	    *stack == NULL ||
	    (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	result = malloc(sizeof(stack_t));
	if (result == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	result->n = (*stack)->n + (*stack)->next->n;
	result->prev = NULL;
	pop(stack, line_number);
	pop(stack, line_number);
	result->next = *stack;
	if (*stack)
		(*stack)->prev = result;
}
