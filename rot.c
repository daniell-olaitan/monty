#include "monty.h"

/**
 * _rotl - rotates the stack left
 * @stack:...
 * @line_number:...
 *
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *last;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	tmp = (*stack)->next;
	last->next = *stack;
	tmp->prev = NULL;
	(*stack)->next = NULL;
	(*stack)->prev = last;
	*stack = tmp;
}

/**
 * _rotr - rotates the stack right
 * @stack:...
 * @line_number:...
 *
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
