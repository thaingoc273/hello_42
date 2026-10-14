//#include <stdio.h>
//
int ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (((*str < 'a') | (*str > 'z')) && ((*str < 'A') | (*str > 'Z')))
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char str[] = "";
	printf("%d", ft_str_is_alpha(&str[0]));
}*/
