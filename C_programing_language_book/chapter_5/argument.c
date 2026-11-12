#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define	MAXLINE 1000

int		ft_getline(char *line, int max);

int		main(int argc, char *argv[])
{
	char	line[MAXLINE];
	int		found;

	found = 0;
	if (argc != 2)
		printf("Input invalid");
	else
		while (ft_getline(line, MAXLINE) > 0)
			if (strstr(line, argv[1]) != NULL)
			{
				printf("%s\n", line);
				found++;
			}
	printf("Number of matching elements %d\n", found);
}

int		ft_getline(char *line, int max)
{
	char	c;
	int		i;

	i = 0;
	while ((c = getchar()) != '\n' && c != EOF)
		line[i++] = c;
	if (i == 0)
		return (-1);
	else
		line[i] = '\0';
	return (i);
}
