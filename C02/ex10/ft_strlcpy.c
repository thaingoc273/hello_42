#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *scr, unsigned int size)
{
	unsigned int	len;
	int	i;

	len = 0;
	i = 0;
	while (scr[len] != '\0')
		len++;
	if (size > 0)
	{
		while ((i < size -1) && (i < len))
		{
			dest[i] = scr[i];
			i++;
		}
		dest[size - 1] = '\0';
	}
	return (len);
}

int	main(void)
{
	char	scr[] = "Hello";
	char	dest[10];
	unsigned int	size;

	size = 2;
	ft_strlcpy(&dest[0], &scr[0], size);
	printf("%s\n", dest);
}
