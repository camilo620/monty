#include "monty.h"
core list;
/**
 * searcher - look for the op code
 * Return: void
 */
void searcher(void)
{
	unsigned int i;
	instruction_t codes[] = {
		{"push", push}, {"pall", pall}, {0, 0}
	};
	if (!list.functions[0])
		return;
	if (list.functions[0][0] == '#')
		return;
	for (i = 0; codes[i].opcode; i++)
	{
		if (strcmp(codes[i].opcode, list.functions[0]) == 0)
		{
			codes[i].f(&list.head, list.command_line);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", list.command_line, list.functions[0]);
	erase_else(1), exit(EXIT_FAILURE);
}
/**
 * lead - sends the first instructions into opcodes
 * @line: takes the line to be sent.
 * Return: void
 */
char **lead(char **line)
{
	unsigned int i;
	char *c = 0, **functions;

	functions = malloc(sizeof(char *) * 3);
	if (!functions)
	{
		fprintf(stderr, "Error: malloc failed\n"), erase_else(1);
		exit(EXIT_FAILURE);
	}
	functions[0] = 0, functions[1] = 0;
	for (i = 0, c = strtok(line[0], " \n\t\v\f"); c && i <= 1; i++)
		functions[i] = strdup(c), c = strtok(0, " \n\t\v\f");
	functions[2] = 0;
	return (functions);
}
/**
 * main - main program
 * @argc: Argument count
 * @av: Arguments
 * Return: 0 if successfull, anything else if not.
 */
int main(int argc, char *av[])
{
	ssize_t c = 0;
	size_t size = 0;

	list.command_line = 0;
	list.head = 0;
	list.mod = 1;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	list.file = fopen(av[1], "r");
	if (!list.file)
		fprintf(stderr, "Error: Can't open file %s\n", av[1]), exit(EXIT_FAILURE);
	while ((c = getline(&list.line, &size, list.file)) != -1)
	{
		list.command_line++;
		list.functions = lead(&list.line), opcoder();
		erase_a(list.functions);
	}
	erase_else(0);
	return (EXIT_SUCCESS);
}
