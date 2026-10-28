#include "ft_stock_str.h"
#include <unistd.h>

struct s_stock_str *ft_strs_to_tab(int ac, char **av);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	char	*lst_str[] = {"Hello", "world"};
	struct s_stock_str	*stock_str;

	stock_str = ft_strs_to_tab(2, &lst_str[0]);
	ft_show_tab(stock_str);
	return (0);
}
