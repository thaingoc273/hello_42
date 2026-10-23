#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*name;

	(void) argc;
	name = argv[0];
	while (*name != '\0')
	{
		write(1, name, 1);
		name++;
	}
	return (0);
}
