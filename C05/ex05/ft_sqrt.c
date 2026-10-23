int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (nb > i * i)
		i++;
	if (nb == i * i)
		return (i);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	printf("Value sqrt is %d\n", ft_sqrt(-4));
	printf("Value sqrt is %d\n", ft_sqrt(0));
	printf("Value sqrt is %d\n", ft_sqrt(1));
	printf("Value sqrt is %d\n", ft_sqrt(3));
	printf("Value sqrt is %d\n", ft_sqrt(9));
}
