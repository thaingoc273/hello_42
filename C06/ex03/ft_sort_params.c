#include <unistd.h>

int	ft_strcmp(char	*s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && s1[idx] != '\0')
		idx++;
	if (s1[idx] == s2[idx])
		return (0);
	else if (s1[idx] < s2[idx])
		return (-1);
	else
		return (1);
}

void	ft_swap_pointer(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_print(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		while (*str[i] != '\0')
		{
			write(1, str[i], 1);
			str[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	len;
	int	i;
	int	j;
	char	**lst;

	len = argc - 1;
	lst = argv + 1;
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(lst[i], lst[j]) == 1)
				ft_swap_pointer(&lst[i], &lst[j]);
			j++;
		}
		i++;
	}
	ft_print(lst, len);
	return (0);
}
