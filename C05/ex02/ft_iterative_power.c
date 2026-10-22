#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	val;

	i = 1;
	val = 1;
	printf("%d", power);
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	while (i <= power)
	{
		val = val * nb;
		i++;
	}
	return (val);
}

int	main(void)
{
	printf("Value of power %d\n", ft_iterative_power(1, -1));
	printf("Value of power %d\n", ft_iterative_power(0, 0));
	printf("Value of power %d\n", ft_iterative_power(1, 0));
	printf("Value of power %d\n", ft_iterative_power(2, 5));
	printf("Value of power %d\n", ft_iterative_power(3, 4));
}
