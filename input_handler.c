/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:02 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/18 17:17:00 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (0);
	return (1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (0);
	return (1);
}

int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (0);
	return (1);
}

int	is_input_valid(char *str, int flag)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		while (ft_isspace(str[i]) == 0)
			i ++;
		if (ft_issign(str[i]) == 0 && str[i + 1] && ft_isdigit(str[i + 1]) == 0)
			i ++;
		if (str[i] && ft_isdigit(str[i]) == 1)
			return (1);
		while (ft_isdigit(str[i]) == 0)
			i ++;
		if (str[i] && ft_isspace(str[i]) == 1)
			return (1);
		if (flag == 1 && str[i] && ft_isspace(str[i]) == 0)
		{
			while (ft_isspace(str[i]) == 0)
				i ++;
			return (str[i] != '\0');
		}
	}
	return (0);
}

// int	is_input_valid(char *str, int flag)
// {
// 	int	i;

// 	i = 0;
// 	if (!str || !str[i])
// 		return (1);
// 	while (str[i])
// 	{
// 		while (str[i] && ft_isspace(str[i]) == 0)
// 			i++;
// 		if (ft_issign(str[i]) == 0 && str[i + 1] && ft_isdigit(str[i + 1]) == 0)
// 			i++;
// 		if (!str[i] || ft_isdigit(str[i]) == 1)
// 			return (1);
// 		while (str[i] && ft_isdigit(str[i]) == 0)
// 			i++;
// 		if (str[i] && ft_isspace(str[i]) == 1)
// 			return (1);
// 		if (flag == 1 && str[i])
// 		{
// 			while (str[i] && ft_isspace(str[i]) == 0)
// 				i++;
// 			return (str[i] != '\0');
// 		}
// 	}
// 	return (0);
// }

int	check_input(char *str, int flag)
{
	if (is_input_valid(str, flag) == 1)
		return (1);
	return (0);
}
