/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:34 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/16 10:23:36 by fshelna          ###   ########.fr       */
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

int	check_duplicate(long *tab, int size)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (index < size)
	{
		j = 0;
		while (j < size)
		{
			if (index != j && tab[index] == tab[j])
				return (1);
			j ++;
		}
		index ++;
	}
	return (0);
}

t_stack_node	*get_node(t_stack *stack, size_t index)
{
	size_t				i;
	t_stack_node	*tmp;

	if (!stack || !stack->node)
		return (NULL);
	i = 0;
	tmp = stack->node;
	while (tmp)
	{
		if (i == index)
		{
			return (tmp);
		}
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}

size_t	get_index(t_stack *stack, int value)
{
	size_t			index;
	t_stack_node	*node;

	if (!stack || !stack->node)
		return (-1);
	index = 0;
	node = stack->node;
	while (node)
	{
		if (node->index == (size_t)value)
			return (index);
		node = node->next;
		index ++;
	}
	return (-1);
}

int	stack_is_sorted(t_stack *stack)
{
	t_stack_node *node;

	if (!stack || !stack->node)
		return (1);
	node = stack->node;
	while (node->next)
	{
		if (node->index + 1==  node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}
