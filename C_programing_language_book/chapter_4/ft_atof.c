#include <stdio.h>
#include <stdlib.h>

double	ft_ten_power(int exp)
{
	double	res;
	int		sign;
	
	res = 1;
	sign = 1;
	if (exp < 0)
	{
		exp = -exp;
		sign = -1;
	}
	while (exp > 0)
	{
		if (sign > 0)
			res = res * 10;
		else
			res = res / 10;
		exp--;
	}
	return (res);
}

int		get_sign(char *str, int *i)
{
	int		sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

double		get_exponent(char *str, int *i)
{
	int		exp_sign;
	int		exp;

	exp_sign = 1;
	exp = 0;
	if (str[*i] == 'e' || str[*i] == 'E')
	{
		(*i)++;
		if (str[*i] == '-' || str[*i] == '+')
		{

			if (str[*i] == '-')
				exp_sign = -1;
			(*i)++;
		}
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			exp = exp * 10 + str[*i] - '0';				
			(*i)++;
		}
	}
	return (ft_ten_power(exp_sign * exp));
}

double	ft_atof(char *str)
{
	double	res;
	int		i;
	int		sign;
	double	exponent;

	res = 0;
	i = 0;
	sign = get_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	exponent = get_exponent(str, &i);
	return (res * sign * exponent);
}

int		main(void)
{
	printf("Value of extracted string %g\n", ft_atof("122323f"));
	printf("Value of extracted string %g\n", ft_atof("  -122df"));
	printf("Value of extracted string %g\n", ft_atof("\n+12e4"));
	printf("Value of extracted string %g\n", ft_atof("\t122E-3dfdf"));
}
