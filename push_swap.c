/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:54:39 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/13 10:38:18 by fshelna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **av)
{
	long	*temp_stack;
	t_stack *stacka;
	t_stack *stackb;
	int		n_elements;
	int 	index;

	stacka  = (t_stack *)malloc(sizeof(t_stack));
	stackb  = (t_stack *)malloc(sizeof(t_stack));
	if (!stacka || !stackb)
		return (0);
	stacka->node = NULL;
	stackb->node = NULL;
	n_elements = 0;
	temp_stack = NULL;
	if (ac < 2 || check_input(av[1]) == 1)
		return (0);
	if (ac == 2)
	{
		if (initialize_single_input(av, &temp_stack, &n_elements) == 1)
			return (0);
	}
	else if (ac > 2)
	{
		if (initialize_multi_input(ac, av, &temp_stack, &n_elements) == 1)
			return (0);
	}
	else 
		return (0);
	if (check_duplicate(temp_stack,n_elements) == 1)
	{
		write(1,"Error\n",ft_strlen("Error\n"));
		free_stack(stacka);
		free_stack(stackb);
		free(temp_stack);
		return (0);
	}
	index = 0;
	while (index < n_elements)
	{
		stack_new_node(&stacka, node_new((int)temp_stack[n_elements - index - 1], 0));
		index ++;
	}
	mega_sort(stacka, stackb, temp_stack, n_elements);
	free_stack(stacka);
	free_stack(stackb);
	free(temp_stack);
	return (0);
}
