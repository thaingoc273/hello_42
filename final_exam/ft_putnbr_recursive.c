#include <stdlib.h>

void	put_number_to_string(int nb, char *str, int i)
{
//	long	n;
	char	c;
	
//	n = nb;
	if (nb < 0 && i == 0)
	{
		//n = -(long)nb;
		*str = '-';
		i++;
	}
	if (nb >= 10 || nb <= -10)
		put_number_to_string(nb / 10, str, i + 1);
	if (nb >= 0)
		c = nb % 10 + '0';
	else
		c = '0' - nb % 10;
	str[i] = c;
}

char	*ft_putnbr_recursive(int nb)
{
char	*str;
char	*str_copy;

str = malloc(16);
if (str == NULL)
	return (NULL);
str_copy = str;
put_number_to_string(nb, str_copy, 0);
return (str);
}

#include <stdio.h>
int		main(void)
{
	printf("Convert to string %s\n", ft_putnbr_recursive(1213));
	printf("Convert to string %s\n", ft_putnbr_recursive(0));
	printf("Convert to string %s\n", ft_putnbr_recursive(-123));
	printf("Convert to string %s\n", ft_putnbr_recursive(121323232));
}
