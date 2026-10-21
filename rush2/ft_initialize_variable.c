#include <stdlib.h>

int	**initialize_result(int n)
{
	int	i;
	int	**result;

	result = malloc(n * sizeof(int *));
	if (result == NULL)
		return (NULL);
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
	return (result);
}

int	*initialize_input(int n)
{
	int	*input;

	input = malloc(4 * n * sizeof(int));
	if (input == NULL)
		return (NULL);
	return (input);
}

void	assign_initial_value(int n, int **result)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < n)
	{
		j = 0;
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
	while (i < 4 * n)
	{
		input[i] = 0;
		i++;
	}
}
void	free_grid_input(int **result, int *input, int n)
{
	int	i;

	if (result != NULL)
	{
		i = 0;
		while (i < n)
			free(result[i++]);
		free(result);
	}
	free(input);
}
