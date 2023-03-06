#include "monty.h"

/**
 * mul - multiplies the 2 top elements of the stack
 * @stack:...
 * @line_number:...
 *
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *result;

	if (stack == NULL ||
	    *stack == NULL ||
	    (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	result = malloc(sizeof(stack_t));
	if (result == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	result->n = (*stack)->next->n * (*stack)->n;
	result->prev = NULL;
	pop(stack, line_number);
	pop(stack, line_number);
	result->next = *stack;
	if (*stack)
		(*stack)->prev = result;
}
