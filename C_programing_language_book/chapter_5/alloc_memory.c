#include <stdio.h>

#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* allocp is the pointer which is free to write*/

char	*alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return (allocp);
	}
	else
		return (0);
}

void	afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

int		main(void)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = 100;
	n2 = 300;
	n3 = 1300;
	allocp = alloc(n1);
	if (allocp)
		printf("Allocation of memory %ld\n", allocp - allocbuf);
	else
		printf("Not enough space\n");
	allocp = alloc(n2);
	if (allocp)
		printf("Allocation of memory %ld\n", allocp - allocbuf);
	else
		printf("there is not enough space\n");
	allocp = alloc(n3);
	if (allocp)
		printf("Allocation of memory %ld\n", allocp - allocbuf);
	else
		printf("there is not enough space\n");
}
