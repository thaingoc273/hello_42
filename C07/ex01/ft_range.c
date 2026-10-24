#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ran;
	unsigned int size;
	int i;

	size = max - min;
	i = min;
	if (min >= max)
		return (NULL);
	ran = malloc(size * sizeof(int));
	while (i < max)
	{
		ran[i - min] = i;
		i++;
	}
	return (ran);
}

#include <stdio.h>

int	main(void)
{
	int	*test;
	int	min;
	int max;
	unsigned int i;

	i = 0;
	min = -10;
	max = 20;// 2147483647;
	test = ft_range(min, max);
	while (i < (max -min))
	{
		printf("%d\n", test[i]);
		i++;
	}
	max = 2147483647;
	a = max - min;
	printf("%u", a);
}
