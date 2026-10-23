#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	*str;

	i = argc - 1;
	while (i >= 1)
	{
		str = argv[i];
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
