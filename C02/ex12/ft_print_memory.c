#include <unistd.h>


#include <unistd.h>

void	ft_puthex(unsigned long nbr, int digits)
{
	char	*base;

	base = "0123456789abcdef";
	if (digits > 1)
		ft_puthex(nbr / 16, digits - 1);
	write(1, &base[nbr % 16], 1);
}

void	ft_print_address(void *addr)
{
	ft_puthex((unsigned long)addr, sizeof(void *) * 2);
	write(1, ": ", 2);
}

void	ft_print_hex(unsigned char *ptr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_puthex(ptr[i], 2);
		else
			write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_chars(unsigned char *ptr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (ptr[i] >= 32 && ptr[i] <= 126)
			write(1, &ptr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	line_size;

	ptr = (unsigned char *)addr;
	while (size > 0)
	{
		line_size = size;
		if (line_size > 16)
			line_size = 16;
		ft_print_address(ptr);
		ft_print_hex(ptr, line_size);
		ft_print_chars(ptr, line_size);
		write(1, "\n", 1);
		ptr += line_size;
		size -= line_size;
	}
	return (addr);
}


int	main(void)
{
	char c;
	char test[] = "This is the 42 berlin. I am Nguyen. I am learning";
	unsigned long hex;

	ft_print_memory(test, 200);

	return (0);
}
