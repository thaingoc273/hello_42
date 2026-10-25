#include <stdlib.h>
#include <limits.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long	size;
	int	i;

	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	size = (long)max - (long)min;
	*range = malloc(size * sizeof(int));
	if (*range == NULL)
		return (-1);
	if (size > INT_MAX)
	{
		*range = NULL;
		return (-1);
	}
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);	
}

#include <stdio.h>

int	main(void)
{
	int *range;
	int	min;
	int	max;

	min = -10;
	max = INT_MAX;
	printf("Size of range %d\n", ft_ultimate_range(&range, min, max));
	if (range != NULL)
		printf("Last value of arr %d\n", range[max - min - 1]);
	
}
