#include "monty.h"

/**
 * _mod - computes the remainder of the division of the top two elements
 * of the stack
 * @stack:...
 * @line_number:...
 *
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *result;

	if (stack == NULL ||
	    *stack == NULL ||
	    (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	result = malloc(sizeof(stack_t));
	if (result == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	result->n = (*stack)->next->n % (*stack)->n;
	result->prev = NULL;
	_pop(stack, line_number);
	_pop(stack, line_number);
	result->next = *stack;
	if (*stack)
		(*stack)->prev = result;
}
