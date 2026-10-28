#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_separator(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (is_separator(*str, charset))
			count++;
		str++;
	}
	return (count);
}

char *copy_str(char *str, int start, int end)
{
	char	*dest;
	int	i;

	i = start;
	dest = malloc(end - start + 2);
	while (i <= end)
	{
		dest[i - start] = str[i];
		i++;
	}
	dest[end - start + 1] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char **str_split;
	int	i;
	int	j;
	int	str_index;

	i = 0;
	j = 0;
	str_index = 0;
	str_split = malloc((count_separator(str, charset) + 2) * sizeof(char *));
	while (str[i])
	{
		if (check_separator(str[i], charset))
		{
			str_split[str_index] = copy_str(str, j, i - 1);
			j = i + 1;
			str_index++;
		}
		i++;
	}
	str_split[str_index] = copy_str(str, j, i - 1);
	str_split[++str_index] = NULL;
	return (str_split);
}

#include <stdio.h>

int	main(void)
{
	char	*str = "Hello how are you. It;is how|we structure our code.";
	char	*charset = " ";
	char	**dest;

	dest = ft_split(str, charset);
	printf("Count separator %d\n", count_separator(str, charset));
	while (*dest)
	{
		printf("%s\n", *dest);
		dest++;
	}
	return (0);
}
