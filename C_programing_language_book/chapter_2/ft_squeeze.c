#include <stdio.h>

int		is_delete(char c, char *s2)
{
	while (*s2 != '\0')
	{
		if (*s2 == c)
			return (1);
		s2++;
	}
	return (0);
}

void	squeeze(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (!is_delete(s1[i], s2))
			s1[j++] = s1[i]; 
		i++;
	}
	s1[j] = '\0';
}

int		main(void)
{
	char	s1[] = "Hello the world";
	char	*s2 = "H ";
	squeeze(s1, s2);
	printf("String after delete: %s", s1);
}
