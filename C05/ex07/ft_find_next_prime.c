int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (nb >= i * i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	while (true)
	{
		if (ft_is_prime(i) == 1)
			return (i);
		i++;
	}
}

#include <stdio.h>
int	main(void)
{
	printf("The next prime number: %d\n", ft_find_next_prime(-10));
	printf("The next prime number: %d\n", ft_find_next_prime(0));
	printf("The next prime number: %d\n", ft_find_next_prime(50));
}
