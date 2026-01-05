/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:54:39 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/05 09:23:58 by fshelna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	log_tab(int *tab)
{
	while (*tab)
	{
		printf("%i, ",*tab);
		tab ++;
	}
}

int main(int ac, char **av)
{
	int	*temp_stack;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (check_input(av[1]) == -1)
		{
			write(1,"Error\n",ft_strlen("Error\n"));
			return (0);
		}
		temp_stack = (int *)malloc(sizeof(int) * count_input_elements(av[1]));
		if (!temp_stack)
			return (0);
		if (!parse_single_input(av[1], temp_stack))
			write(1,"Error\n",ft_strlen("Error\n"));
		log_tab(temp_stack);
	}
	else
	{
		while(ac - 1 > 0)
		{
			if (check_input(av[ac - 1]) == -1)
			{
				write(1,"Error\n",ft_strlen("Error\n"));
				return (0);
			}
			ac --;
		}
	}
}
