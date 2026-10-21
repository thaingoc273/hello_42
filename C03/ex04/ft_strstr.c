#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] != '\0' 
			&& str[i + j] == to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	*str = "Hello everyone, this is 42berlin. I am a student";
	char	*to_find = "thiss";
	char	*result;

	result = ft_strstr(str, to_find);
	printf("%s", result);
}
