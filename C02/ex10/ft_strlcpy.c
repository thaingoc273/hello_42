#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	if (size > 0)
	{
		while ((i < size -1) && (i < len))
		{
			dest[i] = src[i];
			i++;
		}
		dest[size - 1] = '\0';
	}
	return (len);
}

int	main(void)
{
	char	src[] = "Hello";
	char	dest[10];
	unsigned int	size;

	size = 2;
	ft_strlcpy(&dest[0], &src[0], size);
	printf("%s\n", dest);
}
