#include <stdio.h>

int		str_len_memory(char	*s)
{
	char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

int		main(void)
{
	printf("Length of string %d\n", str_len_memory("Hello, how are you"));
	printf("Length of string %d\n", str_len_memory("Hello"));
}
