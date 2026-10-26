#include <stdio.h>

int	check_number(char *number)
{
	while (*number != '\0')
	{
		if (*number < '0' || *number > '9')
			return (0);
		number++;
	}
	return (1);
}

int check_description(char *description)
{
	while (*description != '\0')
	{
		if (*description < ' ' || *description > '~')
			return (0);
		description++;
	}
	return (1);
}

char    *truncate_number(char *str)
{
    int len;

    len = 0;
	while (str[len] != '\0')
		len++;
	while (len > 0 && str[len - 1] == ' ')
		len--;
	str[len] = '\0';
	return (str);
}

char	*truncate_description(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}
