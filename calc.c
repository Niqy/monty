#include "monty.h"
/**
 *add - adds the top two elements of the stack
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum;
	int node = 0;
	stack_t *iterator = *stack;

	while (iterator != NULL)
	{
		node++;
		iterator = iterator->next;
	}
	if (node < 2)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 *sub - subtracts the top element of the stack from the second
 *top element of the stack.
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int dif;
	int node = 0;
	stack_t *iterator = *stack;

	while (iterator != NULL)
	{
		node++;
		iterator = iterator->next;
	}
	if (node < 2)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	dif = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = dif;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 *divide - divides the second top element of the stack by
 *the top element of the stack.
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int quotient;
	int node = 0;
	stack_t *iterator = *stack;

	while (iterator != NULL)
	{
		node++;
		iterator = iterator->next;
	}
	if (node < 2)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	quotient = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = quotient;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 *mul - multiplies the second top element of the
 *stack with the top element of the stack.
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int product;
	int node = 0;
	stack_t *iterator = *stack;

	while (iterator != NULL)
	{
		node++;
		iterator = iterator->next;
	}
	if (node < 2)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	product = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = product;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 *mod - computes the rest of the division of the second top element of
 *the stack by the top element of the stack.
 *@stack: ptr to the top of the stack
 *@line_number: the line number of the command being run
 *
 *Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int module;
	int node = 0;
	stack_t *iterator = *stack;

	while (iterator != NULL)
	{
		node++;
		iterator = iterator->next;
	}
	if (node < 2)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	module = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = module;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
