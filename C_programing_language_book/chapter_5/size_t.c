#include <stdio.h>
#include <stddef.h>

int		main(void)
{
	int		arr[10];

	size_t size = sizeof(arr) / sizeof(int);
	printf("Size of array: %zu\n", size);
}
