#include <stdio.h>
#include <stdlib.h>

#define	STANDARD_LENGTH	2 

int		my_getline(char **line);
void	copy(char **to, char *from);

/* Print the longest line */

int		main(void)
{
	int		len;
	int		max;
	char	*line;
	char	*longest;

	max = 0;
	longest = NULL;
	while ((len = my_getline(&line)) > 0)
		if (len > max)
		{
			max = len;
			copy(&longest, line);
		}
	if (max > 0)
	{
		printf("Longest line length: %d\n", max);
		printf("Longest line: %s\n", longest);
	}
}

int		resize_allocation(char **line, int new_len)
{
	char	*tmp;

	tmp = realloc(*line, new_len + 1);
	if (tmp == NULL)
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	*line = tmp;
	return (1);
}
int		my_getline(char **line)
{
	int		c;
	int		i;
	int		capacity;

	capacity = STANDARD_LENGTH;
	*line = malloc(capacity + 1);
	if (*line == NULL)
		return (0);
	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
	{		
		if (i > capacity && resize_allocation(line, 2 * capacity))
			capacity *= 2;
		(*line)[i] = c;
	}
	if (c == '\n' && resize_allocation(line, capacity + 1))
			(*line)[i++] = c;
	(*line)[i] = '\0';
	if (resize_allocation(line, i + 1))
		return (i - 1);
	return (0);
}

void	copy(char **to, char *from)
{
	int		i;
	char	*tmp;
	char	*start;
	
	i = 0;
	while (from[i] != '\0')
		i++;
	tmp = malloc(i + 1);
	if (tmp == NULL)
		return ;
	start = tmp;
	while ((*tmp++ = *from++) != '\0')
		continue ;
	free(*to);
	*to = start;
}
