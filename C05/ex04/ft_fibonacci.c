int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

#include <stdio.h>

int	main(void)
{
	printf("Value of Fibonacci is %d\n", ft_fibonacci(-1));
	printf("Value of Fibonacci is %d\n", ft_fibonacci(0));
	printf("Value of Fibonacci is %d\n", ft_fibonacci(1));
	printf("Value of Fibonacci is %d\n", ft_fibonacci(2));
	printf("Value of Fibonacci is %d\n", ft_fibonacci(3));
	printf("Value of Fibonacci is %d\n", ft_fibonacci(4));
	printf("Value of Fibonacci is %d\n", ft_fibonacci(5));
	return (0);
}
