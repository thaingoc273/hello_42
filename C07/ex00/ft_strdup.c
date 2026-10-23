#include <stdlib.h>

char	*ft_strdup(char	*src)
{
	int	len;
	int	i;
	char	*dest;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	dest = malloc((len + 1) * sizeof(char));
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char	*src;
	char	*dest;

	src = "Hello";
	dest = ft_strdup(src);
	printf("Copy the string: %s", dest);
	free(dest);
}
