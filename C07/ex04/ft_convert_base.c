#include <stdlib.h>

int ft_check_base(char *base);
int	ft_atoi_base(char *str, char *base);

void	ft_putnbr_base(int number, char *base_to, char **str_convert)
{
	long	n;
	int	base_number;
	
	base_number = ft_check_base(base_to);
	n = number;
	if (number < 0)
	{
		**str_convert = '-';
		(*str_convert)++;
		n = -(long)number;
	}
	if (n >= base_number)
		ft_putnbr_base(n / base_number, base_to, str_convert);
	**str_convert = base_to[n % base_number];
	(*str_convert)++;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	number;
	char	*result;
	char	*copy_result;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	result = malloc(40 * sizeof(char));
	copy_result = result;
	ft_putnbr_base(number, base_to, &copy_result);
	*copy_result = '\0';
	return (result);
}

#include <stdio.h>

int main(void)
{
    char    *str;
    char    *str1;
    char    *str2;
    char    *str3;
	char	*base_from;
	char	*base_to;

    str = " ---+--+2147483648";
    str1 = "2147483647";
    str2 = " a---+--+1234ab567";
    str3 = "-- -+--+12a1234ab567";
    base_from = "00123456789";
	base_to = "0123456789abcdef";
	printf("Extracted string in new base: %s\n", ft_convert_base(str, base_from, base_to));
    printf("Extracted string in new base: %s\n", ft_convert_base(str1, base_from, base_to));
    printf("Extracted string in new base: %s\n", ft_convert_base(str2, base_from, base_to));
    printf("Extracted string in new base: %s\n", ft_convert_base(str3, base_from, base_to));
}
