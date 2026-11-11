#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 500

#define MAXLEN 1000

char	*lineptr[MAXLINES];
int		readlines(char *lineptr[], int nlines);
void	writelines(char *lineptr[], int nlines);
void	ft_qsort(char *lineptr[], int lines);

int		main(void)
{
	int	nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
	//	qsort(lineptr, nlines - 1);
		writelines(lineptr, nlines);
		return (0);
	}
	else
	{
		printf("Error: input error");
		return (1);
	}
}

int 	ft_getline(char *line, int maxlen)
{
	char	c;
	int		i;

	i = 0;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		line[i++] = c;
	}
	if (c == EOF)
		return (-1);
	if (i > maxlen)
		return (-1);
	line[i] = '\0';
	return (i);
}

int		ft_malloc(char **str, int len)
{
	*str = malloc((len + 1) * sizeof(char));
	if (str != NULL)
		return (1);
	else
		printf("Memory allocation failed");
	return (0);
}

int		readlines(char *lineptr[], int maxlines)
{
	int		len;
	int		nlines;
	char	*str;
	char	line[MAXLEN];
//	char	*line;

	nlines = 0;
	while((len = ft_getline(line, MAXLEN)) >= 0)
		if (nlines >= maxlines || (ft_malloc(&str, len) == 0))
			return (-1);
		else
		{
			//line[len] = '\0';
			strcpy(str, line);
			lineptr[nlines++] = str;
		}
	return (nlines);
}

void writelines(char *lineptr[], int nlines)
{
	int		i;
	
	i = 0;
	while (i < nlines)
		printf("%s\n", lineptr[i++]);
}
