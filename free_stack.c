#include "monty.h"
/**
 *free_stack - frees the stack
 *@stack: the head of the stack
 *
 *Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;

	temp = stack->next;
	while (temp != NULL)
	{
		free(stack);
		stack = temp;
		temp = temp->next;
	}
	free(stack);
}
