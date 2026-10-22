#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	val;

	i = 1;
	val = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i <= nb)
	{
		val = val * i;
		i++;
	}
	return (val);
}

int	main(void)
{
	printf("Factorial value: %d\n", ft_iterative_factorial(-3));
	printf("Factorial value: %d\n", ft_iterative_factorial(0));
	printf("Factorial value: %d\n", ft_iterative_factorial(5));
}
