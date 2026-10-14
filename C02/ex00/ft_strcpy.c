//#include <stdio.h>
//
char	*ft_strcpy(char *dest, char *scr)
{
	int	i;

	i = 0;
	while (*(scr + i) != '\0')
	{
		*(dest + i) = *(scr + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	str1[] = "Hello all people";
	char	str2[10];
	char	*str = "Hello";
	char	test[] = "Hello";

	//str = &test[0];
	printf("%c", str[1]);
	printf("%s\n", str);	
	ft_strcpy(&str2[0], &str1[0]);
	printf("%s\n", str2);
	return (0);
}*/
