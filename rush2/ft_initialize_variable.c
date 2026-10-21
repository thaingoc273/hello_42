#include <stdlib.h>

int	initialize_result(int n, int **result)
{
	int	i;

	result = malloc(n * sizeof(int *));
	if (result == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		result[i] = malloc(n * sizeof(int));
		if (result[i] == NULL)
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (0);
		}
		i++;
	}
	return (1);
}

int	initialize_input(int n, int *input)
{
	input = malloc(4 * n * sizeof(int));
	if (input == NULL)
		return (0);
	return (1);
}

void	assign_initial_value(int n, int **result)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < n)
	{	
		while (j < n)
		{
			result[i][j] = 0;
			j++;
		}
		i++;
	}
}

void assign_initial_input(int n, int *input)
{
	int	i;

	i = 0;
	while (i < n)
	{
		input[i] = 0;
		i++;
	}
}

void	free_grid_input(int **result, int *input, int n)
{
	int	i;

	if (result == NULL)
		return ;
	i = 0;
	while (i < n)
	{
		free(result[i]);
		i++;
	}
	free(result);
	free(input);
}
