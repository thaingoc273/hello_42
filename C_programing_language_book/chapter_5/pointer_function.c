#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000

char	*lineptr[MAXLINES];

int		readlines(char *lineptr[], int nlines);
void	writelines(char *lineptr[], int nlines);
void	ft_qsort(void *lineptr[], int left, int right,
				int (*comp)(void *, void *));
int		numcmp(const char *, const char *);
void	ft_swap(void *v[], int i, int j);

int		main(int argc, char **argv)
{
	int		nlines;
	int		numeric;

	numeric = 0;
	if (argc > 1 && !strcmp(argv[1], "-n"))
		numeric = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		ft_qsort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return (0);
	}
	else
	{
		printf("Invalid input \n");
		return (1);
	}
}

int		numcmp(const char *s1, const char *s2)
{
	double	v1;
	double	v2;

	v1 = atof(s1);
	v2 = atof(s2);
	
	if (v1 < v2)
		return (-1);
	else if (v1 > v2)
		return (1);
	else
		return (0);
}

void ft_swap(void *v[], int i, int j)
{
	void *tmp;

	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

int		partition(void *lineptr[], int low, int high, int (*comp)(void *, void *))
{
	char	*pivot;
	char	*tmp;
	int		i;
	int		j;

	pivot = lineptr[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (comp(lineptr[j], pivot) < 0)
		{
			ft_swap(lineptr, i, j);
			i++;
		}
		j++;
	}
	ft_swap(lineptr, i, high);
	return (i);
}

void	ft_qsort(void *lineptr[], int start, int end, int (*comp)(void *, void *))
{
	int		i;

	if (start < end)
	{
		i = partition(lineptr, start, end, comp);
		ft_qsort(lineptr, start, i - 1, comp);
		ft_qsort(lineptr, i + 1, end, comp);
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

	nlines = 0;
	while((len = ft_getline(line, MAXLEN)) >= 0)
		if (nlines >= maxlines || (ft_malloc(&str, len) == 0))
			return (-1);
		else if (len > 0)
		{
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
