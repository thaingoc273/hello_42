//#include <unistd.h>
//#include <stdio.h>

int ft_check_row_left(int r, int value, int n, int **result);
int ft_check_row_right(int r, int value, int n, int **result);
int ft_check_col_top(int c, int value, int n, int **result);
int ft_check_col_bottom(int c, int value, int n, int **result);




int	ft_can_place(int idx, int value, int n, int **result)
{
	int	i;
	int	r;
	int	c;

	r = idx / n;
	c = idx % n;
	i = 0;
	while (i < r)
	{
		if (result[i][c] == value)
			return (0);
		i++;
	}
	i = 0;
	while (i < c)
	{
		if (result[r][i] == value)
			return (0);
		i++;
	}
	return (1);
}

int	ft_validate_height(int idx,  int n, int *input, int **result)
{
	int	r;
	int	c;

	r = idx / n;
	c = idx % n;
	if (c == n - 1)
	{
		if (ft_check_row_left(r, input[2 * n + r], n, result) == 0)
			return (0);
		if (ft_check_row_right(r, input[3 * n + r], n, result) == 0)
			return (0);
	}
	if (r == n - 1)
	{
		if (ft_check_col_top(c, input[c], n, result) == 0)
			return (0);
		if (ft_check_col_bottom(c, input[n + c], n, result) == 0)
			return (0);
	}
	return (1);
}

void	ft_put_value(int idx, int value, int n, int **result)
{
	int	r;
	int	c;
	
	r = idx / n;
	c = idx % n;
	result[r][c] = value;
}

int	solver(int idx, int n, int *input, int **result)
{
	int	value;
	
	if (idx == n * n)
		return (1);	
	value = 1;
	while (value <= n)
	{
		if (ft_can_place(idx, value, n, result)
			&& (ft_validate_height(idx, n, input, result)))
			{				
				ft_put_value(idx, value, n, result);
				if (solver(idx + 1, n, input, result))
					return (1);
				ft_put_value(idx, 0, n, result);
			}
		value++;
	}
	return (0);
	
}
/*
int	main(int argc, char **argv)
{
	int	*input;
	int	n = 4;
	int	(*result)[n];
	int	found;

	result = malloc(4 * sizeof(*array))

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (ft_parse_input(argv[1], input) == 0)
		write(1, "Error\n", 1);
		return (1);
	else if (solver(0, 4, input, result, found) == 1)
		ft_output(n, result);
	else
		write(1, "Error\n", 6);
	int result[4][4] = {
			{1, 2, 3, 4},
			{2, 3, 4, 1},
			{3, 4, 1, 2},
			{4, 1, 2, 3}
				};
	printf("%d", ft_can_place(3, 3, 4, 4, result));

}*/
