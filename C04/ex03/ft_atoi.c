#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sgn;
	int val;

	i = 0;
	sgn = 1;
	val = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sgn = -sgn;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		val = val * 10 + str[i] - '0';
		i++;
	}
	val = val * sgn;
	return (val);
}

int	main(void)
{
	char	*str;
	char	*str1;
	char	*str2;
	char	*str3;

	str = " ---+--+1234ab567";
	str1 = "a";
	str2 = "a---+--+1234ab567";
	str3 = "---+--+a1234ab567";
	printf("Extracted value: %d\n", ft_atoi(str));
	printf("Extracted value: %d\n", ft_atoi(str1));
	printf("Extracted value: %d\n", ft_atoi(str2));
	printf("Extracted value: %d\n", ft_atoi(str3));
}
