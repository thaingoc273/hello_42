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

#include <stdio.h>

int	main(void)
{
	printf("Check the prime number %d\n", ft_is_prime(-1));
	printf("Check the prime number %d\n", ft_is_prime(0));
	printf("Check the prime number %d\n", ft_is_prime(1));
	printf("Check the prime number %d\n", ft_is_prime(2));
	printf("Check the prime number %d\n", ft_is_prime(3));
	printf("Check the prime number %d\n", ft_is_prime(4));
	printf("Check the prime number %d\n", ft_is_prime(5));
	printf("Check the prime number %d\n", ft_is_prime(29));
}
