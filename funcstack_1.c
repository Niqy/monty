#include "global.h"
#include "monty.h"

/**
 *push - pushes an element to the stack.
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *value;
	int i = 0, j = 0;

	value = malloc(sizeof(char) * 12);
	if (value == NULL)
		return;

	while (line[i] < '0' || line[i] > '9')
	{
		if (line[i] == '\0')
		{
			printf("L%u: usage: push integer\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		if (line[i] == '-')
		{
			value[j] = line[i];
			j++;
		}
		i++;
	}
	while (line[i] != ' ' && line[i] != '\0'
	       && line[i] >= '0' && line[i] <= '9')
	{
		value[j] = line[i];
		i++;
		j++;
	}
	if (line[i] != ' ' && line[i] != '\0')
	{
		printf("L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value[j] = '\0';
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	node->n = atoi(value);
	node->prev = NULL;
	if (*stack == NULL)
		node->next = NULL;
	else
	{
		node->next = *stack;
		(*stack)->prev = node;
	}
	*stack = node;
	free(value);
}

/**
 *pall - prints all the values on the stack,
 *starting from the top of the stack
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *iterator;

	(void) line_number;
	iterator = *stack;
	if (*stack == NULL)
		return;
	while (iterator != NULL)
	{
		printf("%d\n", iterator->n);
		iterator = iterator->next;
	}
}

/**
 *getopcode - obtains the opcode of a Monty file from a buffer
 *
 *Return: ptr to a string containing the opcode
 */
char *getopcode(void)
{
	int i = 0, j = 0;
	char *buffer;

	buffer = malloc(sizeof(char) * 10);
	if (buffer == NULL)
		return (NULL);

	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i] != '\0')
	{
		buffer[j] = line[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return (buffer);
}

/**
 *compareopcode - compares opcodes and runs associated functions
 *@stack: ptr to the top of the stack
 *@line_number: line number of command
 *@opcode: the opcode for Monty interpretor
 *
 *Return: void
 */
void compareopcode(stack_t **stack, unsigned int line_number, char *opcode)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", divide},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{NULL, NULL}
	};

	while (ops[i].opcode != NULL)
	{
		if (_strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}

	printf("L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
