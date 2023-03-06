#include "monty.h"

/**
 * _push - implements monty push instruction
 * @stack: ...
 * @line_number: ...
 *
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *node;

	if (stack == NULL)
		return;

	if (valid == false)
	{
		fprintf(stderr, "L%d: usage: push integer\n",
			(int)line_number);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = argument;
	node->next = NULL;
	node->prev = NULL;
	top = *stack;
	if (top != NULL)
	{
		node->next = top;
		top->prev = node;
	}

	*stack = node;
}
