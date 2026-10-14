//#include <stdio.h>
//
bool	ft_is_alphanumeric(char c)
{
	return ((c <= '9' && c >= '0') || (c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'));
}

char	*ft_capitalize_char(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c + 'A' - 'a';
	return c;
}

char	*ft_lowercase_char(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c = *c - 'A' + 'a';
	return c;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (*str == '\0')
		return "";
	str = ft_capitalize_char(str);
	while (*(str + i) != '\0')
	{
		if (!ft_is_alphanumeric(*(str + i - 1)))
			ft_capitalize_char(str + i);
		else
			ft_lowercase_char(str + i);
		i++;
	}
	return str;
}
/*
int	main(void)
{
	char	str[] = "hi,df dfdf,  how are you? 42words forty-two; fifty+and+one";
	char	test[] = "a";

	printf("%s\n", ft_strcapitalize(&str[0]));
	printf("%s\n", ft_strcapitalize(&test[0]));
}*/
