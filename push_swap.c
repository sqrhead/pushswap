/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:54:39 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/12 22:50:37 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "loggers.h"


int main(int ac, char **av)
{
	long	*temp_stack;
	t_stack *stacka;
	t_stack *stackb;
	int		n_elements;
	// int		chunk_size;

	stacka  = (t_stack *)malloc(sizeof(t_stack));
	stackb  = (t_stack *)malloc(sizeof(t_stack));
	if (!stacka || !stackb)
		return (0);
	stacka->node = NULL;
	stackb->node = NULL;

	if (ac < 2) // No Input
	{
		write(1,"Error\n",ft_strlen("Error\n"));
		return (0);
	}
	if (check_input(av[1]) == 1) // Input not valid
		return (0);
	if (ac == 2)
	{
		n_elements = count_input_elements(av[1]);
		temp_stack = (long *)malloc(sizeof(long) * n_elements);
		if (!temp_stack)
			return (0);
		if (parse_single_input(av[1], temp_stack) == 1)
			return (0);
	}
	else if (ac > 2)
	{
		n_elements = ac - 1;
		temp_stack = (long *)malloc(sizeof(long) * n_elements);
		if (!temp_stack)
			return (0);
		if (parse_mul_input(av, temp_stack,	n_elements) == 1)
		{
			return (0);
		}
	}
	// char **div = ft_split(av[1],' ');

	// int read_index = 0;
	// int	write_index = 0;

	// while (div[read_index])
	// {
	// 	// if (!div[read_index][0])
	// 	// {
	// 	// 	printf("SKIPPED\n");
	// 	// 	read_index ++;
	// 	// 	continue;
	// 	// }
	// 	temp_stack[write_index] = ft_atol(div[read_index]);
	// 	if (temp_stack[write_index] > INT_MAX || temp_stack[write_index] < INT_MIN)
	// 	{
	// 		write(1,"Error\n",ft_strlen("Error\n"));
	// 		free_pp(div);
	// 		free(temp_stack);
	// 		return (0);
	// 	}
	// 	write_index ++;
	// 	read_index ++;
	// }
	// duplicate check
	if (check_duplicate(temp_stack,n_elements) == 1)
	{
		write(1,"Error\n",ft_strlen("Error\n"));
		// free_pp(div);
		free(temp_stack);
		return (0);
	}
	// fill stack
	int index = 0;
	while (index < n_elements)
	{
		stack_new_node(&stacka, node_new((int)temp_stack[n_elements - index - 1],0));
		index ++;
	}

	mega_sort(stacka, stackb, temp_stack, n_elements);
	if (stack_is_sorted(stacka) == 0)
		printf("************* SORTED ******************\n");

	printf("********* STACK_FREED *******************\n");
	free_stack(stacka);
	free_stack(stackb);
	// free_stack(stack_b);
	// free_pp(div);
	free(temp_stack);
	return (0);
}
