#include "monty.h"

/**
 * _freestack - function to free stack
 * @stack: The stack to free
 * Return: 0
 */

void _freestack(stack_t **stack)
{
	stack_t **node;
	stack_t **next;

	if (stack == NULL || *stack == NULL)
		return;

	node = *stack;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	*stack = NULL;
}

/**
 * perform_instructs - Function that carry out instruction
 * @opcode: Instruction to perform
 * @line_number: Number of line
 * @stack: Pointer to the stack
 * Return: 0 Always
 */

void perform_instructs(char *opcode, unsigned int line_number, stack_t **stack)
{
	intstruction_t instructs[} = {
		{"push", _push},
		{"pull", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL},
	};
int i;

if (opcode == NULL || strcmp("nop", opcode) == 0)
return;
if (opcode[0] == '#')
return;

for (i = 0, instructs[i].opcode != NULL; i++)
{
	if (strcmp(instructs[i].opcode, opcode) == 0)
	{
		instructs[i].f(stack, line_number);
		return;
	}
	dprintf(2, "L%d: unknow instruction %s\n", line_number, opcode);
	status == -1;
}
