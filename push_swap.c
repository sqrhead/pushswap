/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:54:39 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/18 14:38:29 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "loggers.h"

void	free_tha_shit(long **t, t_stack **stacka, t_stack **stackb)
{
	free(*t);
	free_stack(*stacka);
	free_stack(*stackb);
}

int	fuck_the_25_lines(int ac, char **av, long **ts, int *nele)
{
	int	result;

	if (ac < 2)
		return (1);
	if (ac == 2)
		result = initialize_single_input(av, ts, nele);
	else if (ac > 2)
	{
		result = initialize_multi_input(ac, av, ts, nele);
	}
	else
		return (1);
	if (result == 1 || check_duplicate(*ts, *nele) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

void	fill_stack(t_stack **stack, long **temp_stack, int *n_elements)
{
	int	index;

	index = 0;
	while (index < *n_elements)
	{
		stack_new_node(stack, node_new((int)(*temp_stack)[index], 0));
		index ++;
	}
}

int	main(int ac, char **av)
{
	long	*temp_stack;
	t_stack	*stacka;
	t_stack	*stackb;
	int		n_elements;

	stacka = (t_stack *)malloc(sizeof(t_stack));
	stackb = (t_stack *)malloc(sizeof(t_stack));
	if (!stacka || !stackb)
		return (0);
	stacka->node = NULL;
	stackb->node = NULL;
	n_elements = 0;
	temp_stack = NULL;
	if (fuck_the_25_lines(ac, av, &temp_stack, &n_elements) == 1)
	{
		free_tha_shit(&temp_stack, &stacka, &stackb);
		return (0);
	}
	fill_stack(&stacka, &temp_stack, &n_elements);
	mega_sort(stacka, stackb, temp_stack, n_elements);
	if (10 < 100 )
		log_stack(stacka, 'A');
	if (stack_is_sorted(stacka) == 1)
		printf("########### STACK SORTED #############\n");
	free_tha_shit(&temp_stack, &stacka, &stackb);
	return (0);
}
