#include <stdlib.h>

int	string_length(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

int	concatenation_length(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += string_length(strs[i]);
		i++;
	}
	total_len += (size - 1) * string_length(sep);
	return (total_len);
}

void	add_string(char **str1, char *str2, int pos)
{
	int	i;

	i = 0;
	while (*str2 != '\0')
	{
		(*str1)[i + pos] = *str2;
		i++;
		str2++;
	}
}

char	*empty_return(void)
{
	char	*str_cat;

	str_cat = malloc(sizeof(char));
	str_cat[0] = '\0';
	return (str_cat);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_cat;
	int	i;
	int	pos;
	int	total_length;

	i = 0;
	pos = 0;
	if (size == 0)
		return (empty_return());
	total_length = concatenation_length(size, strs, sep) + 1;
	str_cat = malloc(total_length);
	while (i < size)
	{
		add_string(&str_cat, strs[i], pos);
		if (i != size - 1)
			add_string(&str_cat, sep, pos + string_length(strs[i]));
		pos += string_length(strs[i]) + string_length(sep);
		i++;
	}
	str_cat[total_length] = '\0';
	return (str_cat);
}

#include <stdio.h>

int	main(void)
{
	char	*strs[2];
	char	*sep;
	char	*dest;

	sep = "w";
	strs[0] = "Hello";
	strs[1] = "World";
	dest = ft_strjoin(0, strs, sep);
	printf("Concaternate string %s", dest);
	free(dest);
}
