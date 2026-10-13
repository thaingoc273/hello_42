#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
/*	int	t_div;
	int	t_mod;


	t_div = a / b;
	t_mod = a % b;
	div = &t_div;
	mod = &t_mod;
	*/

	*div = a / b;
	*mod = a % b;
	printf("%d", *div);
	printf("%d", *mod);
}

int	main(void)
{
	//int	def = 0;
	int	div;// = &def;
	int	mod;// = &def;

	ft_div_mod(50, 4, &div, &mod);
}
