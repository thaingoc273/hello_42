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

#include <stdlib.h>
#include <stdio.h>

int	*ft_parse_input(char *str, int *input, int n)
{
	int	i;
//	int	*lst;

//	lst = malloc(n * 4 * sizeof(int));
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
	if (i != 8 * n - 1)
		return (0);
	return (1);
}

int	main(void)
{
	char	*test = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	int		n = 4;
	int		*lst;

	lst = malloc(n * 4 * sizeof(int));
	lst = ft_parse_input(test, lst, n);
	if (!lst)
		printf("Format error");
	else
		printf("Format right");
	//printf("%d", lst[15]);
	return (0);
}
