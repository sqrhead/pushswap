/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:31 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/13 10:48:32 by fshelna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strlen(const char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        count ++;
        str ++;
    }
    return (count);
}

long ft_atol(char *str)
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

int	count_input_elements(char *str)
{
	int	i;
	int	nele;

	nele = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i ++;
		if (!str[i])
			break;
		if (ft_isdigit(str[i]) || ft_issign(str[i]))
		{
			nele ++;
			if (ft_issign(str[i]))
				i ++;
			while (str[i] && ft_isdigit(str[i]))
                i++;
		}
	}
	return (nele);
}

int get_len_str(char *str)
{
	int	index;

	index = 0;
	while (str[index] && !ft_isspace(str[index]))
		index ++;
	return (index);
}

int	parse_single_input(char *str,long *tab)
{
	char	**div;
	int		index;

	div = ft_split(str,' ');
	index = 0;
	while (div[index])
	{
		tab[index] = ft_atol(div[index]);
		if (tab[index] > INT_MAX || tab[index] < INT_MIN)
		{
			write(1,"Error\n",ft_strlen("Error\n"));
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
		tab[index] = ft_atol(str[n_elements - index - 1]);
		if (tab[index] > INT_MAX || tab[index] < INT_MIN)
		{
			write(1,"Error\n",ft_strlen("Error\n"));
			return (1);
		}
		index ++;
	}
	return (0);
}