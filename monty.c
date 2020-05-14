#define _GNU_SOURCE
#include "global.h"
#include "monty.h"
char *line;
/**
 *main - entry point for monty
 *@argc: the number of command line arguments
 *@argv: the array of command line argument strings
 *
 *Return: 0 always
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	int i = 0, j = 0;
	FILE *file;
	unsigned int line_number = 0;
	char *opcode;
	ssize_t read_chars = 0;
	size_t size;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_chars != -1)
	{
		line = NULL;
		size = 0;
		i = 0;
		j = 0;
		read_chars = getline(&line, &size, file);
		line_number++;
		while (line[j] == ' ')
			j++;
		if (line[j] == '\n' || line[j] == '#')
			continue;
		while (line[i] != '\n' && line[i] != '\0')
			i++;
		line[i] = '\0';
		if (line[0] == '\0')
			break;
		opcode = getopcode();
		compareopcode(&stack, line_number, opcode);
		free(opcode);
		free(line);
	}
	fclose(file);
	free(line);
	free_stack(stack);
	return (0);
}
