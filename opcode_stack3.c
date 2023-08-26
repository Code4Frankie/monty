#include "monty.h"


/**
 * _mul -  Multiplies the second top element
 * owith the top element of the stack.
 *
 * @stack: Head stack to print it.
 * @line_number: The line number.
 *
 * Return: 0
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		status = -1;
		return;
	}

	node = *stack;
	(*stack) = (*stack)->next;

	(*stack)->n = ((*stack)->n) * (node->n);
	free(node);
}


/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 *
 * @stack: Head stack to print it.
 * @line_number: The line number.
 *
 * Return: 0
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		status = -1;
		return;
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		status = -1;
		return;
	}

	node = *stack;
	(*stack) = (*stack)->next;

	(*stack)->n = ((*stack)->n) % (node->n);
	free(node);
}


/**
 * _pchar - prints the char at the top of the stack.
 *
 * @stack: Head stack to print it.
 * @line_number: The line number.
 *
 * Return: 0
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		status = -1;
		return;
	}

	temp = (*stack)->n;
	if (temp < 0 || temp > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		status = -1;
		return;
	}

	printf("%c\n", temp);
}
