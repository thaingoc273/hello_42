#include <stdio.h>

int		partition(int a[], int low, int high)
{
	int		i;
	int		j;
	int		tmp;

	i = low;
	int		pivot = a[high];
	for (j = low; j < high; j++)
	{
		if (a[j] <= pivot)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
		}
	}
	tmp = a[i];
	a[i] = a[high];
	a[high] = tmp;
	return (i);
}

void	quick_sort(int a[], int low, int high)
{
	int		p;

	if (low < high)
	{
		p = partition(a, low, high);
		quick_sort(a, low, p - 1);
		quick_sort(a, p + 1, high);
	}
}

void	print_arr(int a[], int len)
{
	int		i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int		main(void)
{
	int		a[] = {4, 5, 7, 2, 1, 3};
	//printf("Position of pivot: %d\n", partition(a, 0, 5));
	//print_arr(a, 6);

	quick_sort(a, 0, 5);
	print_arr(a, 6);
}
