#include <stdio.h>
#include <unistd.h>
	
int ft_check_duplicate(char *base, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < i - 1)
	{
		k = j + 1;
		while (k < i)
		{
			if (base[j] == base[k])
				return (1);
			k++;
		}
		j++;
	}
	return (0);
}

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < '0' || base[i] > 'z')
			return (0);
		if (base[i] > '9' && base[i] < 'A')
			return (0);
		if (base[i] > 'Z' && base[i] < 'a')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	if (ft_check_duplicate(base, i))
		return (0);
	return (i);
}

void	ft_putnbr_base_unsigned(int nbr, char *base, int n)
{
	int	c;

	if (nbr != 0)
	{
		ft_putnbr_base_unsigned(nbr / n, base, n);
		if (nbr < 0)
			c = -(nbr % n);
		else
			c = nbr % n;
		write(1, &base[c], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!ft_check_base(base))
		return ;
	else if (nbr == 0)
		write(1, &base[0], 1);
	else if (nbr > 0)
		ft_putnbr_base_unsigned(nbr, base, ft_check_base(base));
	else
	{
		write(1, "-", 1);
		ft_putnbr_base_unsigned(nbr, base, ft_check_base(base));
	}
}

int	main(void)
{
	char	*base = "0123456789ABCDEF";
	int		nbr = -2147483648;

	printf("Check base: %d\n", ft_check_base(base));
	ft_putnbr_base(nbr, base);
}
