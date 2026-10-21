#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_parse_input(char *str, int *input, int n);
void	ft_output(int n, int **result);
int	get_size(char *str);
int	solver(int idx, int n, int *input, int **result);
int	ft_check_col_top(int c, int value, int n, int **result);
int	ft_check_row_left(int c, int value, int n, int **result);

int	**initialize_result(int n)
{
	int	**result;
	int	i;

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
			return (NULL);
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

void	ft_putstr(char * str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	print_result(int n, char *str, int *input, int **result)
{
	if (!(ft_parse_input(str, input, n)))
	{
		ft_putstr("Errorparse\n");
		return (0);
	}
	if (solver(0, n, input, result))
	{
		ft_output(n, result);
	}
	else
		ft_putstr("Errornosol\n");
	return (1);	
}

int	main(int argc, char **argv)
{
	int	*input;
	int	**result;
	char	*str;
	int	n;

	if (argc != 2)
	{
		ft_putstr("Error arg not macht\n");
		return (0);
	}
	n = get_size(argv[1]);
	if (n == 0)
	{
		ft_putstr("Error input invalid");
		return (0);
	}
	str = argv[1];
	input = initialize_input(n);
	result = initialize_result(n);
	assign_initial_value(n, result);
	assign_initial_input(n, input);
	if (input == NULL || result == NULL)
	{
		free_grid_input(result, input, n);
		return (1);
	}
	print_result(n, str, input, result);

	//printf("Size of grid %d\n", n);
	//printf("Value of grid at (1,1) %d", result[1][1]);
}
