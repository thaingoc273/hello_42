#include <unistd.h>
#include <stdio.h>

int ft_check_row_left(int r, int value, int n, int **result);
int ft_check_row_right(int r, int value, int n, int **result);
int ft_check_col_top(int c, int value, int n, int **result);
int ft_check_col_bottom(int c, int value, int n, int **result);
void ft_output(int n, int **result);

static int is_solvable;

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
	{	
		if (ft_validate_height(idx - 1, n, input, result))
			ft_output(n, result);
		write(1, "\n", 1);
//		*found = 1;
//		return (1);
	}
	value = 1;
	while (value <= n)
	{
		if (ft_can_place(idx, value, n, result))
		{
			ft_put_value(idx, value, n, result);
			if (ft_validate_height(idx, n, input, result))
			{
				solver(idx + 1, n, input, result);
//				if (solver(idx + 1, n, input, result))
//					return (1);
			}
			ft_put_value(idx, 0, n, result);
		}
		value++;
	}
	//return (is_solvable);	
}
