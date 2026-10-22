#include <unistd.h>

void ft_putnbr_unsigned(int nb)
{
	char	c;

	if (nb != 0)
	{
		ft_putnbr_unsigned(nb / 10);
		if (nb < 0)
			c = -(nb % 10) + '0';
		else
			c = nb % 10 + '0';
		write(1, &c, 1);
	}
}

void ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr_unsigned(nb);
	}
	else
		ft_putnbr_unsigned(nb);
}

int	main(void)
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
