#include <unistd.h>
#include <stdio.h>

int	ft_count_visible_building(int *lst, int n)
{
	int	i;
	int	count;
	int	max_hight;

	i = 1;
	count = 1;
	max_hight = lst[0];
	while (i < n)
	{
		if (lst[i] > max_hight)
		{
			count++;
			max_hight = lst[i];
		}
		i++;
	}
	return (count);
}

int	ft_check_row_left(int r, int value, int n, int result[n][n])
{
	int	array[n];
	int	i;

	i = 0;
	while (i < n)
	{
		array[i] = result[r][i];
		i++;
	}
	if (ft_count_visible_building(array, n) == value)
		return (1);
	return (0);
}
int	ft_check_row_right(int r, int value, int n, int result[n][n])
{
	int	array[n];
	int	i;

	i = 0;
	while (i < n)
	{
		array[i] = result[r][n - i - 1];
		i++;
	}
	if (ft_count_visible_building(array, n) == value)
		return (1);
	return (0);
}

int	ft_check_col_top(int c, int value, int n, int result[n][n])
{
	int	array[n];
	int	i;

	i = 0;
	while (i < n)
	{
		array[i] = result[i][c];
		i++;
	}
	if (ft_count_visible_building(array, n) == value)
		return (1);
	return (0);
}


int	ft_check_col_bottom(int c, int value, int n, int result[n][n])
{
	int	array[n];
	int	i;

	i = 0;
	while (i < n)
	{
		array[i] = result[n - i - 1][c];
		i++;
	}
	if (ft_count_visible_building(array, n) == value)
		return (1);
	return (0);
}

void main()
{
	int	array[] = {3, 4, 1, 2};
	int	result[4][4] = {
   			 {1, 2, 3, 4},
  			 {2, 3, 4, 1},
  			 {3, 4, 1, 2},
			 {4, 1, 2, 3}
			};
//	printf("%d/n", ft_count_visible_building(array, 4));
	printf("%d\n", ft_check_row_left(0, 4, 4, result));		
}
