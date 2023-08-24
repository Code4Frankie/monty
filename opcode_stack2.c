#include "monty.h"

/**
 * _swap - Function that swaps the top two elements of the stack
 * @stack: The stack
 * @line_number: The line number
 * Return: 0
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int i;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		status = -1;
		return;
	}

	node = (*stack)->next;
	i = node->n;
	node->n = (*stack)->n;
	(*stack)->n = i;
}


/**
 * _add - Function that adds two top elements of the stack
 * @stack: Stack to print from
 * @line_number: The line number
 * Return: 0
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		status = -1;
		return;
	}

	node = *stack;
	(*stack) = (*stack)->next;

	(*stack)->n = ((*stack)->n) + (node->n);
	free(node);
}

/**
 * _sub - Function that subs the top element from the second element of stack
 * @stack: The stack
 * @line_number: The line number
 * Return: 0
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		staus = -1;
		return;
	}
	node = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n = ((*stack)->n) - (node->n);
	free(node);
}
