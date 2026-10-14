//#include <stdio.h>
//
int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		printf("%d", *str);
		if ((*str < 32) | (*str > 126))
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str[2];

	str[0] = 'a';
	str[1] = '\t';
	printf("%d", ft_str_is_printable(&str[0]));
}*/
