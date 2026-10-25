#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ran;
	long size;
	int i;

	i = min;
	if (min >= max)
		return (NULL);
	size = (long)max - (long)min;
	ran = malloc(size * sizeof(int));
	if (ran == NULL)
		return (NULL);
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
	int	max;
	long	i;

	i = 0;
	min = -10;
	max = 20;
	test = ft_range(min, max);
	if (test != NULL)
	{
		while (i < ((long)max - (long)min))
		{
			printf("%d\n", test[i]);
			i++;
		}
	}
	free(test);
}
