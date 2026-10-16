#include <stdio.h>

int	ft_strcmp(char	*s1, char *s2)
{
	int	res;
	int	idx;

	idx = 0;
	while (s1[idx] == s2[idx] && s1[idx] != '\0')
		idx++;
	if (s1[idx] == s2[idx])
		return (0);
	else if (s1[idx] < s2[idx])
		return (-1);
	else
		return (1);

}

int	main(void)
{

	printf("%d\n", ft_strcmp("ABC", "ABC"));
	printf("%d\n", ft_strcmp("ABCa", "ABC"));
	printf("%d\n", ft_strcmp("aBCa", "ABC"));
	printf("%d\n", ft_strcmp("", "ABC"));
	return (0);
}
