#include <unistd.h>
#include <stdio.h>

char	lst_alpha[3] = "ABC";

void	ft_print_path(char *cbn)
{
	int	idx;
	
	idx = 0;
	while (cbn[idx] != '\0')
	{
		write(1, &cbn[idx], 1);
		idx++;
	}
}

int	ft_str_len(char *c)
{
	int	len;

	len = 0;
	while (c[len] != '\0')
		len++;	
	return (len);
}

void	ft_add_path(char *cbn, char c)
{
	int	i;

	i = ft_str_len(cbn);
	cbn[i] = c;
	cbn[i + 1] = '\0';
}

void	ft_pop_path(char *cbn)
{
	int	i;

	i = ft_str_len(cbn);
	if (i > 0)
	{
		cbn[i -1] = '\0';
	}		
}

void	ft_print_all_combination(int start_idx, char *cbn)
{
	int	i;

	if (start_idx == ft_str_len(&lst_alpha[0]))
	{
		ft_print_path(cbn);		
	}
	else
	{
		i = 0;
		while (i < ft_str_len(&lst_alpha[0]))
		{
			ft_add_path(cbn, lst_alpha[i]);
			i++;
			ft_print_all_combination(start_idx + 1, cbn);
			ft_pop_path(cbn);
		}
	}
}

int	main(void)
{
	char	*cbn = "";
	
	write(1, cbn, 1);
	ft_print_path("Hello");
	ft_add_path(&lst_alpha[0], 'D');
	printf("%s", lst_alpha);
	printf("%d", ft_str_len("Hello"));
	ft_pop_path(&lst_alpha[0]);
	printf("%s", lst_alpha);
	ft_print_all_combination(0, cbn);
}
