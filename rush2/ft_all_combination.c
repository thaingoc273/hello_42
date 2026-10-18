#include <unistd.h>
#include <stdio.h>

void	ft_print_path(char *cbn)
{
	int	idx;
	
	idx = 0;
	while (cbn[idx] != '\0')
	{
		write(1, &cbn[idx], 1);
		idx++;
	}
	write(1, "\n", 1);
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

void	ft_print_all_combination(int start_idx, char *cbn, char *lst_alpha, int *found)
{
	int	i;
	int	len;

	//if (*found == 1)
	//	return;
	len = ft_str_len(lst_alpha);
	if (start_idx == len)
	{
		ft_print_path(cbn);
		*found = 1;
		return;
	}
	else
	{
		i = 0;
		while (i < len)
		{
			ft_add_path(cbn, lst_alpha[i]);
			i++;
			ft_print_all_combination(start_idx + 1, cbn, lst_alpha, found);
			ft_pop_path(cbn);
			if (*found == 1)
				return;
		}
	}
}

int	main(void)
{
	char	cbn[4];
	int	found;

	found = 0;
	char	*lst_alpha;
	lst_alpha = "ABC";	
	ft_print_all_combination(0, cbn, lst_alpha, &found);
}
