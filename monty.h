#ifndef MONTHY_H
#define MONTHY_H

#define _POSIX_C_SOURCE 200809L

/*libaries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int status; /* program status */

/* functions */
void perform_instructs(char *opcode, unsigned int line_n, stack_t **stack);
void _push(stack_t **stack, unsigned int line_num);
void _pall(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_num);
void _pop(stack_t **stack, unsigned int line_num);
void _swap(stack_t **stack, unsigned int line_num);
void _add(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void _mul(stack_t **stack, unsigned int line_num);
void _mod(stack_t **stack, unsigned int line_num);
void _pchar(stack_t **stack, unsigned int line_num);

/* free function */
void _freestack(stack_t **stack);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _checkinteger(const char *str); /* check for integer */

#endif /*MONTY_H*/
