#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	*generic_function(void *, void *, int);

int		main(int argc, char **argv)
{
	int 	a = 42;
	printf("%d\n", *(int*) generic_function(&a, "Hello", 1));
	printf("%s\n", (char*) generic_function(&a, "Hello", 2));
}

void   *generic_function(void *a, void *b, int	type)
{
	static int	number = 42;
	static char	text[] = "Hello";
	if (type == 1)
		return (a);
	if (type == 2)
		return (b);
}
