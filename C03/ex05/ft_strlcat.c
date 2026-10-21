#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;

	i = 0;
	while(dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i + 1] = '\0';
	while (src[j] != '\0')
	{
		j++;
		i++;
	}
	return (i);
}

int	main(void)
{
	char	dest[30] = "This is 42berlin";
	char	*src = "";

	printf("Total length %d\n", ft_strlcat(dest, src, 20));
	printf("String after concaternation: %s\n", dest);
}
