//#include <stdio.h>
//
void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i <= (size - 2))
	{
		j = i + 1;
		while (j <= (size -1))
		{
			if (*(tab + i) > *(tab + j))
			{
				tmp = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = tmp;
			}
			j++;
		}
		i++;
	}
}
/*
int	main(void)
{
	int	num[] = {3, 4, -2, 5, -1};
	int	len = sizeof(num) / sizeof(num[0]);

	ft_sort_int_tab(num, len);
	printf("%d", len);
	printf("%d", num[0]);
	printf("%d", num[1]);
	printf("%d", num[2]);
	printf("%d", num[3]);
	printf("%d", num[4]);
}*/
