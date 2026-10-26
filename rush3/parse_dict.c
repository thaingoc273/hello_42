#include <stdlib.h>
#include "rush02.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	check_number(char *number);
int check_description(char *description);
char *truncate_number(char *str);
char *truncate_description(char *str);

int	read_line(int fd, char **line)
{
	char	c;
	int	len;
	int byte_read;

	len = 0;
	*line = malloc(1024 * sizeof(char));
	(*line)[0] = '\0';
	byte_read = read(fd, &c, 1);
	if (byte_read == -1 || byte_read == 0)
		return (0);
	while (c != '\n')
	{
		(*line)[len] = c;
		len++;
		read(fd, &c, 1);
	}
	(*line)[len] = '\0';
	return (1);
}

void	extract_string(char *str, char **number, char **description)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*number = malloc(100 * sizeof(char));
	*description = malloc(100 * sizeof(char));
	if (str[0] == '\0')
	{
		(*number)[0] = '\0';
		(*description)[0] = '\0';
		return ;
	}
	while (str[i] != ':')
	{
		(*number)[i] = str[i];
		i++;
	}
	(*number)[i] = '\0';
	while (str[i + 1] != '\0')
	{
		(*description)[j] = str[i + 1];
		i++;
		j++;
	}
	(*description)[i] = '\0';
	*number = truncate_number(*number);
	*description = truncate_description(*description);
}

int	extract_line(char *str, t_dict *entry)
{
	char	*number;
	char	*description;

	extract_string(str, &number, &description);
	if (check_number(number) && check_description(description))
	{
		if ((number[0] == '\0' && description[0] != '\0'))
			return (0);
		if ((number[0] != '\0' && description[0] == '\0'))
			return (0);
		(*entry).key = number;
		(*entry).value = description;
		return (1);
	}
	return (0);
}

int	open_file(char *dict_name)
{
	int	fd;
	
	fd = open(dict_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	return (fd);
}

int	parse_dict(int fd, char *dict_name, t_dict **dict)
{
	int	entry_number;
	char	*line;
	t_dict	entry;

	*dict = malloc(1024 * sizeof(t_dict));	
	if (dict == NULL)
		return (0);
	entry_number = 0;
	if (!fd)
		return (0);	
	while (read_line(fd, &line))
	{
		if (extract_line(line, &entry))
		{
			if (*(entry.key) != '\0' && *(entry.value) != '\0')
			{
				(*dict)[entry_number].key = entry.key;
				(*dict)[entry_number].value = entry.value;
				entry_number++;
			}
		}
	}
	return (entry_number);
}

int	main(void)
{
	t_dict	*dict;
	char	*dict_name;
	int	entry_number;
	int	i;
	char	*line;
	int	fd;
	t_dict	entry;
	char	*number;
	char	*description;

	dict_name = "numbers.dict";	
/*	fd = open_file(dict_name);
	read_line(fd, &line);
	read_line(fd, &line);
	read_line(fd, &line);
	printf("%s", line);
	extract_line(line, &entry);*/
//	extract_string("012   :    Zeros", &number, &description);
//	printf("File number %d\n", fd);
//	extract_line("0  :     Zeros", &entry);
//	printf("%s\n", entry.key);
//	printf("%s\n", entry.value);

	i = 0;
	fd = open_file(dict_name);
	entry_number = parse_dict(fd, dict_name, &dict);
	if (!entry_number)
		printf("Error dict\n");
	else
	{
		while (i < entry_number)
		{
			printf("%s",dict[i].key);
			printf(":%s\n", dict[i].value);
			i++;
		}
	}
	return (0);	
}
