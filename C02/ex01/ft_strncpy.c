//#include <stdio.h>
//#include <string.h>
//
char	*ft_strncpy(char *dest, char *scr, unsigned int n)
{
	int	i;

	i = 0;
	while (scr[i] != '\0')
	{
		if (i ==  n)
			return dest;
		else
		{
			dest[i] = scr[i];
			i++;
		}
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	scr[] = "Hello";
	char	dest[20];

	ft_strncpy(&dest[0], &scr[0], 1);
	printf("%s", dest);
	return (0);
}*/
