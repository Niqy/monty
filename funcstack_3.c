#include "monty.h"

/**
 * _strcmp - Compares the value of chars in two different strings 1 by 1
 * @s1: first string
 * @s2: second string
 * Return: difference between the value in the strings
 */

int _strcmp(char *s1, char *s2)
{
	int ch = 0;

	while ((s1[ch] != '\0' && s2[ch] != '\0') && s1[ch] == s2[ch])
	{
		ch++;
	}
	return (s1[ch] - s2[ch]);
}

/**
 *pchar - prints the char at the top of the stack, followed by a new line.
 *@stack: the ptr to the top of the stack
 *@line_number: the line number in the Monty file
 *
 *Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n > 127)
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
}

