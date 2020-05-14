#include "monty.h"

/**
 *pint - prints the value at the top of the stack, followed by a new line.
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 *pop - removes the top element of the stack.
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
	free(temp);
}

/**
 *swap - swaps the top two elements of the stack.
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	int nodes = 0;
	stack_t *iterator = *stack;

	while (iterator != NULL)
	{
		nodes++;
		iterator = iterator->next;
	}
	if (nodes < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 *nop - doesn’t do anything.
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
