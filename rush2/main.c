#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_parse_input(char *str, int *input, int n);
void	ft_output(int n, int **result);
int	get_size(char *str);
int	solver(int idx, int n, int *input, int **result);
int	ft_check_col_top(int c, int value, int n, int **result);
int	ft_check_row_left(int c, int value, int n, int **result);
void	ft_putstr(char *str);
int	print_result(int n, char *str, int *input, int **result);
int	initialize_result(int n, int **result);
int	initialize_input(int n, int *input);
void	assign_initial_value(int n, int **result);
void	assign_initial_input(int n, int *input);
void	free_grid_input(int **result, int *input, int n);

int	check_arg(int arg_c, char **arg_v)
{
	int	n;

	if (arg_c != 2)
	{
		ft_putstr("Error arg not macht\n");
		return (0);
	}
	n = get_size(arg_v[1]);
	if (n == 0)
	{
		ft_putstr("Error input invalid");
		return (0);
	}
	return (n);
}

int	main(int argc, char **argv)
{
	int	*input;
	int	**result;
	char	*str;
	int	n;

	printf("Run through the main");
	n = check_arg(argc, argv);
	printf("Size of matrix %d", n);
	if (n)
	{
		str = argv[1];
		initialize_input(n, input);
		initialize_result(n, result);
		assign_initial_value(n, result);
		assign_initial_input(n, input);
		if (input == NULL || result == NULL)
		{
			free_grid_input(result, input, n);
			return (0);
		}
		print_result(n, str, input, result);
	}
	return (1);
}
