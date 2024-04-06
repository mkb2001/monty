

#ifndef MONTY_MONTY_H
#define MONTY_MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <strings.h>

extern FILE *file;

extern int FIFO;

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

void (*ref_func(char *opcode))(stack_t **, unsigned int);
char *get_opcode(char *inst_line);
void push(stack_t **stack, unsigned int line_number);
int lineReader(stack_t **stack, char *line, int line_number);
void enqueue(stack_t **new_block, stack_t **stack);
void push_to_stack(stack_t **new_block, stack_t **stack);
void free_stack_t(stack_t **stack);
void pall(stack_t **stack, unsigned int line_number);
void print_errmsg_opcodefail(stack_t **stack, int line_number, char *opcode);
int stoi(char *str);
int is_spaces(char *inst_line);
int is_empty(char *inst_line);
int is_newline(char *inst_line);
void print_errmsg_argfail(void);
void print_errmsg_openfail(char **pString);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
#endif
