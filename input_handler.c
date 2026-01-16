/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:02 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/16 09:54:10 by fshelna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (0);
	return (1);
}

int ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (0);
	return (1);
}

int ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (0);
	return (1);
}

int	is_input_valid(char *str, int flag)
{
	int	index;

	index = 0;
	if (!str)
		return (1);
	while (str[index])
	{
		while (ft_isspace(str[index]) == 0)
			index ++;
		if (ft_issign(str[index]) == 0 && str[index + 1] && ft_isdigit(str[index + 1]) == 0)
			index ++;
		if (str[index] && ft_isdigit(str[index]) == 1)
			return (1);
		while(ft_isdigit(str[index]) == 0)
			index ++;
		if (str[index] && ft_isspace(str[index]) == 1)
			return(1);
		if (flag == 1 && str[index] && ft_isspace(str[index]) == 0)
		{	
			while (ft_isspace(str[index]) == 0) 
				index ++;
			if (str[index])
				return (1);
		}
	}
	return (0);
}

int	check_input(char *str, int flag)
{
	if (is_input_valid(str, flag) == 1)
	{
		// write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}