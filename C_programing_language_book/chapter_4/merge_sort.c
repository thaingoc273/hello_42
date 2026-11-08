#include <stdio.h>

void	merge(int a[], int aux[], int low, int mid, int high)
{
	int		i;
	int		j;
	int		k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
			aux[k++] = a[i++];
		else
			aux[k++] = a[j++];
	}
	while (i <= mid)
		aux[k++] = a[i++];
	while (j <= high)
		aux[k++] = a[j++];
	for (i = low; i <= high; i++)
		a[i] = aux[i];
}

void	merge_sort(int a[], int aux[], int low, int high)
{
	int		mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(a, aux, low, mid);
		merge_sort(a, aux, mid + 1, high);
		merge(a, aux, low, mid, high);
	}
}

void print_arr(int arr[], int len)
{
	int		i;

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
}

int		main(void)
{
	int		a[] = {0, 1, 9, 3, 5, 2, 4, 7, 0, 12, 14};
	int		b[11];

	merge_sort(a, b, 0, 10);
	print_arr(a, 11);

}
