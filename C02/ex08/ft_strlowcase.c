//#include <stdio.h>
//
char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) >= 'A') && (*(str + i) <= 'Z'))
			*(str + i) += 'a' - 'A';
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = "Hello123";

	printf("%s", ft_strupcase(&str[0]));
}*/
