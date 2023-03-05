#include "monty.h"

/**
 * print_error - prints all kinds of error in monty
 * @count: number of arguments passed
 *
 */
void print_error(int count, ...)
{
	int i;
	va_list args;

	va_start(args, count);
	for (i = 0; i < count; ++i)
		fprintf(stderr, "%s", va_arg(args, char *));

	va_end(args);

	exit(EXIT_FAILURE);
}
