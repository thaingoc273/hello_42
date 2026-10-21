#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (1);
}

int	main(void)
{
	printf("%d\n", ft_strncmp("ABCae", "ABCa", 4));
	printf("%d\n", ft_strncmp("ABCa", "ABC", 4));
	printf("%d\n", ft_strncmp("aBCa", "ABC", 0));
	printf("%d\n", ft_strncmp("", "ABC", 1));
	return (0);
}
