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

void	put_number_to_string(int nb, char *str, int i)
{
//	long	n;
//	cha	
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
		str[i] = nb % 10 + '0';
	else
		str[i] = '0' - nb % 10;
}

char	*ft_putnbr_recursive(int nb)
{
char	*str;
int		i;
//char	*str_copy;

i = 0;
str = malloc(16);
while (i < 16)
	str[i++] = '\0';
if (str == NULL)
	return (NULL);
//str_copy = str;
put_number_to_string(nb, str, 0);
//str_copy = '\0';
swap_str(str);
return (str);
}

#include <stdio.h>
int		main(void)
{
	printf("Convert to string %s\n", ft_putnbr_recursive(-2147483648));
	printf("Convert to string %s\n", ft_putnbr_recursive(0));
	printf("Convert to string %s\n", ft_putnbr_recursive(-123));
	printf("Convert to string %s\n", ft_putnbr_recursive(2147483647));
}
