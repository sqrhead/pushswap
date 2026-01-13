/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:54:39 by fshelna           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2026/01/13 12:05:34 by fshelna          ###   ########.fr       */
=======
/*   Updated: 2026/01/12 23:34:18 by sqrhead          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tha_shit(long **tab, t_stack **stacka, t_stack **stackb)
{
	free(*tab);
	free_stack(*stacka);
	free_stack(*stackb);	
}

int	fuck_the_25_lines(int ac, char **av, long **temp_stack, int *n_elements)
{
	if (ac < 2 || check_input(av[1]) == 1)
		return (1);
	if (ac == 2)
	{
		if (initialize_single_input(av, temp_stack, n_elements) == 1)
		{	
			write(1,"Error\n",ft_strlen("Error\n"));
			return (1);
		}
	}
	else if (ac > 2)
	{
		if (initialize_multi_input(ac, av, temp_stack, n_elements) == 1)
		{
			write(1,"Error\n",ft_strlen("Error\n"));
			return (1);
		}
	}
	else 
		return (1);
	if (check_duplicate(*temp_stack, *n_elements) == 1)
	{	
		write(1,"Error\n",ft_strlen("Error\n"));
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
		stack_new_node(stack, node_new((int)*temp_stack[*n_elements - index - 1], 0));
		index ++;
	}
}

int main(int ac, char **av)
{
	long	*temp_stack;
	t_stack	*stacka;
	t_stack	*stackb;
	int		n_elements;

	stacka  = (t_stack *)malloc(sizeof(t_stack));
	stackb  = (t_stack *)malloc(sizeof(t_stack));
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
<<<<<<< Updated upstream
	printf("n_elements %i\n", n_elements);
	fill_stack(&stacka, &temp_stack, &n_elements);
=======
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

>>>>>>> Stashed changes
	mega_sort(stacka, stackb, temp_stack, n_elements);
	free_tha_shit(&temp_stack, &stacka, &stackb);
	return (0);
}