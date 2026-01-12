/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:54:39 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/12 11:00:48 by fshelna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "loggers.h"

int main(int ac, char **av)
{
	long	*temp_stack;
	t_stack *stacka;
	t_stack *stackb;
	int		chunk_size;

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
	int n_elements = count_input_elements(av[1]);
	temp_stack = (long *)malloc(sizeof(long) * n_elements);
	if (!temp_stack)
		return (0);
	char **div = ft_split(av[1],' ');
//	log_str(div);
	int index = 0;
	while (div[index])
	{
		temp_stack[index] = ft_atol(div[index]);
		if (temp_stack[index] > INT_MAX || temp_stack[index] < INT_MIN)
		{
			write(1,"Error\n",ft_strlen("Error\n"));
			free_pp(div);
			free(temp_stack);
			return (0);
		}
		index ++;
	}
	if (check_duplicate(temp_stack,n_elements) == 1)
	{
		write(1,"Error\n",ft_strlen("Error\n"));
		free_pp(div);
		free(temp_stack);
		return (0);
	}
	index = 0;
	while (index < n_elements)
	{
		stack_new_node(&stacka, node_new((int)temp_stack[n_elements - index - 1],0));
		index ++;
	}
	int len_stack = stack_get_len(stacka);
	bubble_sort(temp_stack, n_elements);
	generate_chunks(temp_stack, &stacka);
	chunk_size = chunk_get_size(n_elements);
	int	chunk_index = 0;
	if (chunk_size == 0)
	{
		printf("**** CHUNK_SIZE_ZERO **** \n");
		if (n_elements <= 3)
			sort_three(&stacka);
		else
			sort_five(stacka, stackb);
	}
	else
	{	
		// push b
		while (chunk_index  < chunk_size)
		{
			while (chunk_contain(chunk_index, stacka) == 0)
			{
				// find number index
				while (stacka->node->chunk_n != chunk_index)
					rotate_a(stacka);
				push_b(stacka, stackb);
			}
			chunk_index ++;
		}
		// push a 
		int lenb = stack_get_len(stackb);
		while (lenb > 0)
		{
			while (stackb->node->index != lenb - 1)
			{
				if (get_index(stackb, lenb -1) < lenb / 2)
					rotate_b(stackb);
				else
					reverse_rotate_b(stackb);
			}
			push_a(stacka, stackb);
			lenb = stack_get_len(stackb);
		}
	}

	if (stack_is_sorted(stacka) == 0)
		printf("************* SORTED ******************\n");
	if (stacka != NULL)
	{
		printf("********* STACK_FREED *******************\n");
		free_stack(stacka);
		free_stack(stackb);
	}
	// free_stack(stack_b);
	free_pp(div);
	free(temp_stack);
	return (0);
}
