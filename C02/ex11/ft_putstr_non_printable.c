#include <stdio.h>
#include <unistd.h>

void	ft_puthex(char c)
{
	char *base;
       
	base = "0123456789abcdef";
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			ft_puthex(str[i]);
		}
		i++;
	}
	
}

int	main(void)
{
	char	*str;

	str = "Hello \n chung toi \t";
	ft_putstr_non_printable(str);
}
