#include <stdlib.h>

void	swap_value(char *s1, char *s2)
{
	char	c;
	
	c = *s1;
	*s1 = *s2;
	*s2 = c;
}

void	swap_str(char *str)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[len] != '\0')
		len++;
	if (str[0] != '-')
		while (i < (len / 2))
			swap_value(&str[i++], &str[len - i - 1]);
	else
	{
		i = 1;
		while (i <= (len / 2))
			swap_value(&str[i++], &str[len - i]);
	}
}

char	*zero_return(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

void	ft_putnbr_str(int nb, char *str)
{
	char	c;
	int		i;

	i = 0;
	if (nb < 0)
	{
		str[0] = '-';		
		i++;
	}
	while (nb != 0)
	{
		if (nb > 0)
			c = nb % 10 + '0';
		else
			c = -(nb % 10) + '0';
		str[i++] = c;
		nb = nb / 10;	
	}
	str[i + 1] = '\0';
	swap_str(str);
}

char	*ft_putnbr(int nb)
{
	char	*str;
	
	str = malloc(16);
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		return (zero_return(str));
	ft_putnbr_str(nb, str);
	return (str);
}

#include <stdio.h>
#include <string.h>

int		main(void)
{
	printf("Return value: %s\n", ft_putnbr(-2147483648));
	printf("Return value: %s\n", ft_putnbr(2147483647));
	printf("Return value: %s\n", ft_putnbr(0));
	printf("Return value: %s\n", ft_putnbr(-123));
	printf("Length of string %lu\n", strlen(ft_putnbr(-123)));
	printf("Return value: %s\n", ft_putnbr(123));
}
