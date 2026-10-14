//#include <stdio.h>
//
int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 'a') | (*str > 'z'))
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = "12";

	printf("%d", ft_str_is_lowercase(&str[0]));
}*/
