#include "monty.h"

/**
 * push - implements monty push instruction
 * @stack: ...
 * @line_number: ...
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	char str[1024];
	stack_t *top, *node;

	if (valid == false)
		print_error(3, "L", itoa(line_number, str, 10),
			    ": usage: push integer\n");

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		print_error(1, "Error: malloc failed\n");

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
