#ifndef MONTY_H
#define MONTY_H
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \t\n\b\a"

/**
 *
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 **/

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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 **/

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 **/

typedef struct line_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  line_t;
extern line_t line;
extern char **tok;

int malloc_err(void);
int usage_err(void);
int open_err(char *filename);
int unknown_op_err(char *opcode, unsigned int counter);
int no_int(unsigned int counter);
int pop_err(unsigned int counter);
int pint_err(unsigned int counter);
int short_stack_err(unsigned int counter, char *op);
int div_err(unsigned int counter);
int pchar_err(unsigned int counter, char *message);
void set_op_tok_error(int error_code);


void push(stack_t **head, unsigned int counter);
void f_pall(stack_t **head, unsigned int counter);
void pint(stack_t **head, unsigned int counter);
void pop(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void divide(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void mod(stack_t **head, unsigned int counter);
void comments(stack_t **head, unsigned int counter);
void pchar(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void rotl(stack_t **head, unsigned int counter);
void rotr(stack_t **head, unsigned int counter);
void stack(stack_t **head, unsigned int counter);
void queue(stack_t **head, unsigned int counter);

char *g_int(int m);
char **strtow(char *str, char *delim);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);
unsigned int _abs(int n);

void free_stack(stack_t **stack);
int init(stack_t **stack);
int mode(stack_t *stack);
void tokens(void);
unsigned int token_arr(void);
int run(FILE *script_fd);
int check_mode(stack_t *stack);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);

#endif
