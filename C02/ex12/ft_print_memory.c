#include <unistd.h>
#include <stdio.h>



void	*ft_print_memory(void *addr, unsigned int size)
{
	
}

int	main(void)
{
	char c;
	unsigned long dec;

	c = 'c';
	dec = (unsigned long) &c;
	printf("Memory address %p\n", &c);
	printf("%lu\n", dec);
	return (0);
}
