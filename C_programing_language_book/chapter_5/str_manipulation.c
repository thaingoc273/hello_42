#include <stdio.h>

void	ft_strcpy(char *dest, char *src)
{
	while (*dest++ = *src++)
		;
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1++ == *s2++)
		;
	return (*(--s1) - *(--s2));
}

int		main(void)
{
	char	dest[20];
	char	*src = "Hello how are you";
	char	*s1 = "ABCDE";
	char	*s2 = "ABCDE";
	
	ft_strcpy(dest, src);
	printf("Copy string %s\n", dest);
	printf("Compare two strings %d\n", ft_strcmp(s1,s2));
}
