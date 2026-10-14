//#include <stdio.h>
//
int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 'A') | (*str > 'Z'))
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = "AbC";

	printf("%d", ft_str_is_lowercase(&str[0]));
}*/
