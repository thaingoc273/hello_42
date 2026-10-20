#include <unistd.h>
//#include <stdio.h>

void ft_output(int n, int result[n][n])
{
	int	i;
	int	j;
	char	c;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c = result[i][j] + '0'; 
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
/*
int	main(void)
{
	int result[4][4] = {
			{1, 2, 3, 4},
			{2, 3, 4, 1},
			{3, 4, 1, 2},
			{4, 1, 2, 3}
				};
	ft_output(4, result);
}*/
