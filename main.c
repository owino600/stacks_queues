#include "monty.h"

int main(int argc, char *argv[])
{
	char *script_filename = argv[1];
	FILE *script_fd = fopen(script_filename, "r");
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <monty_script_file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	script_filename = argv[1];
	script_fd = fopen(script_filename, "r");

	if (script_fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", script_filename);
		return EXIT_FAILURE;
	}

	stack = NULL;

	init_stack(&stack);

	if (check_mode(&stack) != STACK)
	{
		fprintf(stderr, "Error: Invalid stack mode\n");
		fclose(script_fd);
		free_stack(&stack);
		return EXIT_FAILURE;
	}

	if (!run_monty(script_fd))
	{
		fclose(script_fd);
		free_stack(&stack);
		return EXIT_FAILURE;
	}

	fclose(script_fd);
	free_stack(&stack);
	free_tokens();

	return EXIT_SUCCESS;
}
