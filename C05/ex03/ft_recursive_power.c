int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power -1));
}

#include <stdio.h>

int	main(void)
{
	printf("Value of recursive power: %d\n", ft_recursive_power(0, -3));
	printf("Value of recursive power: %d\n", ft_recursive_power(0, 0));
	printf("Value of recursive power: %d\n", ft_recursive_power(0, 1));
	printf("Value of recursive power: %d\n", ft_recursive_power(3, 5));
	return (0);
}
