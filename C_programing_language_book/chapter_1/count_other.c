#include <stdio.h>

int		main(void)
{
	char	c;
	char	c1;
	
	while((c = getchar()) == ' ')
		continue;	
	putchar(c);
	while((c1 = getchar()) != EOF)
	{
		if (c1 != ' ' || (c1 == ' ' && c != ' '))
			putchar(c1);
		c = c1;
	}
}

