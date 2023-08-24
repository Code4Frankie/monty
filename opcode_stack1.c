#include "monty.h"

/**
 * _push - Pushes an element to the stack
 * @stack: Stack to push on
 * @line_number: Line number
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");

	stack_t = *new node;

	if (arg == NULL || !check_integer(arg))
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		status = -1;
		return;
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		status = -1;
		return;
	}
	new_node->n = atoi(argc);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack == NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * _pall - Prints all the values on the stack
 * @stack: Stack to print from
 * @line_number: Line number
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack *node;

	if (stack == NULL || *stack == NULL)
		return;

	(void)line_number;
	node = *stack;

	while (node != NULL)
	{
		printf("%d/n", node->next);
		node = node->next;
	}
}

/**
 * _pint - Prints the topmost value of the stack
 * @stack: The stack to print from
 * @line_number: The line number
 * Return: 0
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(2,  "L%d: can't pint, stack empty\n", line_number);
		status = -1;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - Removes the top element of the stack
 * @stack: Stack to print
 * @line_number: The line number
 * Return: 0
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		status = -1;
		return;
	}

	node = *stack;
	(*stack) = node->next;
	free(node);
}
