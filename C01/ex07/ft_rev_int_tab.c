#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i <= (size / 2) - 1)
	{
		tmp = *(tab + i);
		*(tab + i) = *(tab + size - i - 1);
		*(tab + size - i - 1) = tmp;
		i++;
	}
}

int	main(void)
{
	int num[] = {10, 11, 12, 13, 1};
	int size;

	size = sizeof(num)/sizeof(num[0]);
	ft_rev_int_tab(num, size);
	printf("%d", num[0]);
	printf("%d", num[size - 1]);
}
