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
