#include <unistd.h>
#include <stdio.h>

int	ft_parse_input(char *str, int *input, int n);
int	solver(int idx, int n, int *input, int **result);

void	ft_output(int n, int **result)
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

void	ft_putstr(char *str)
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
		printf("Find solution");
		ft_output(n, result);
	}
	else
		ft_putstr("Errornosol\n");
	return (1);	
}
