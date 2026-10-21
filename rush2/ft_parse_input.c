/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thanguye <thanguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:41:48 by thanguye          #+#    #+#             */
/*   Updated: 2026/10/17 16:11:58 by thanguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>

int	ft_parse_input(char *str, int *input, int n)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if ((i % 2) != 0)
		{
			if (str[i] != ' ')
			return (0);
		}
		else if (str[i]  < '1' || str[i] - '0' > n)
			return (0);
		else 
			input[i / 2] = str[i] - '0';
		i++;		
	}
	return ((i +1) % 8 == 0);
}
int	get_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if ((i + 1) % 8 ==0)
		return ((i + 1) / 8);
	return (0);
}
/*
int	main(void)
{
	char	*test = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	int		n;
	int		*lst;

	printf("Kich thuoc cua mang: %d", get_size(test));
	if (get_size(test) != 0)
	{
		n = get_size(test);
		lst = malloc(n * 4 * sizeof(int));
		ft_parse_input(test, lst, n);
	}	
	if (!lst)
		printf("Format error");
	else
		printf("Format right");
	
	return (0);
}*/
