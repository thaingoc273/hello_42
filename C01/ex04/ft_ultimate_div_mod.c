//#include <unistd.h>
//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *a / *b;
	*b = tmp % *b;
	//printf("%d", *a);
	//printf("%d", *b);	
}
/*
int	main()
{
	int	val1;
	int	val2;

	val1 = 32;
	val2 = 5;
	ft_ultimate_div_mod(&val1, &val2);
}*/
