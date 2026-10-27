#include <stdlib.h>
#include "ft_stock_str.h"

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	str_copy(char **dest, char *src)
{
	int	len;

	len = 0;
	while (src[len] != '\0')
	{
		(*dest)[len] = src[len];
		len++;
	}
	(*dest)[len] = '\0';
}

int	 assign_stock(char *str, t_stock_str *stock_str)
{
	(*stock_str).size = str_len(str);
	(*stock_str).str = str;
	(*stock_str).copy = malloc((*stock_str).size + 1);
	if ((*stock_str).copy == NULL)
		return (0);
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;
	t_stock_str	*stock_str;

	i = 0;
	stock_str = malloc((ac + 1) * sizeof(t_stock_str));
	if (stock_str == NULL)
		return (NULL);
	while (i < ac)
	{
		if (!assign_stock(av[i], &(stock_str[i])))
		{
			while (i > 0)
				free(stock_str[--i].copy);
			free(stock_str);
			return (NULL);
		}
		str_copy(&(stock_str[i].copy), av[i]);
		i++;
	}
	stock_str[ac].str = 0;
	return (stock_str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*lst_str[] = {"Hello", "42berlin", "all", "Students"};
	struct s_stock_str *stock_str;
	
	stock_str = ft_strs_to_tab(4, &lst_str[0]);
	printf("The first element %s\n", stock_str[0].str);
	printf("The second element %s\n", stock_str[1].str);
	printf("The third  element %s\n", stock_str[2].str);
	printf("The last element %s\n", stock_str[3].str);
	printf("Check the end of list %d\n", stock_str[4].str == 0);
	return (0);
}*/
