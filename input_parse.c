/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:31 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/18 17:59:47 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		index;
	int		sign;
	long	result;

	index = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[index]) == 0)
		index ++;
	if (ft_issign(str[index]) == 0)
	{
		if (str[index] == '-')
			sign *= -1;
		index ++;
	}
	while (str[index] && ft_isdigit(str[index]) == 0)
	{
		result = (result * 10) + (str[index] - '0');
		index ++;
	}
	return (result * sign);
}

int	get_len_str(char *str)
{
	int	index;

	index = 0;
	while (str[index] && !ft_isspace(str[index]))
		index ++;
	return (index);
}

int	parse_single_input(char *str, long *tab, int nele)
{
	char	**div;
	int		index;

	index = 0;
	if (check_input(str, 0))
		return (1);
	div = ft_split(str, ' ');
	while (index < nele && div[index])
	{
		tab[index] = ft_atol(div[nele - index - 1]);
		if (tab[index] > INT_MAX || tab[index] < INT_MIN)
		{
			free_pp(div);
			return (1);
		}
		index ++;
	}
	free_pp(div);
	return (0);
}

int	parse_mul_input(char **str, long *tab, int n_elements)
{
	int	index;

	index = 0;
	while (index < n_elements)
	{
		if (check_input(str[n_elements - index], 1) == 1)
			return (1);
		tab[index] = ft_atol(str[n_elements - index]);
		if (tab[index] > INT_MAX || tab[index] < INT_MIN)
			return (1);
		index ++;
	}
	return (0);
}
