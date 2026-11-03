#include <stdio.h>

int		main(void)
{
	int		c;
	int		count_line;

	count_line = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++count_line;
	printf("The number of lines %d\n", count_line);
}
