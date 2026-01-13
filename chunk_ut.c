/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_ut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:47:54 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/13 19:45:57 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_contain(int chunk_n, t_stack *stack)
{
	t_stack_node	*tmp;

	if (!stack || !stack->node)
		return (-1);
	tmp = stack->node;
	while (tmp)
	{
		if (tmp->chunk_n == (size_t)chunk_n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	chunk_get_size(int stack_size)
{
	if (stack_size <= 5)
		return (0);
	else if (stack_size <= 10)
		return (3);
	else if (stack_size <= 50)
		return (5);
	else if (stack_size <= 100)
		return (stack_size / 6);
	else if (stack_size <= 500)
		return (stack_size / 20);
	else
		return (stack_size / 15);
}

void	generate_chunks(long *tab, t_stack **stack)
{
	int				i;
	int				j;
	int				len;
	int				chunk_len;
	t_stack_node	*tmp;

	if (!*stack || !(*stack)->node)
		return ;
	i = 0;
	j = 0;
	len = stack_get_len(*stack);
	chunk_len = chunk_get_size(len);
	tmp = (*stack)->node;
	while (i < len)
	{
		while (tmp->value != (int)tab[i])
			tmp = tmp->next;
		if (i > chunk_len * (j + 1))
			j++;
		tmp->chunk_n = j;
		tmp->index = i;
		tmp = (*stack)->node;
		i++;
	}
}
