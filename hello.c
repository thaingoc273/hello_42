#include <unistd.h>

void	ft_write(void)
{
	write(1, "Hello", 5);
}

int	main(void)
{
	ft_write();
}
