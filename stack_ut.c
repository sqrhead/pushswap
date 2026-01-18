/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:28 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/18 20:01:21 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_new_node(t_stack **stack, t_stack_node *node)
{
	t_stack_node	*tmp;

	if (!*stack)
	{
		*stack = (t_stack *)malloc(sizeof(t_stack));
		if (!*stack)
			return ;
		(*stack)->node = node;
		(*stack)->node->next = NULL;
		return ;
	}
	tmp = (*stack)->node;
	(*stack)->node = node;
	(*stack)->node->next = tmp;
}

int	stack_get_len(t_stack *stack)
{
	int				len;
	t_stack_node	*tmp;

	len = 0;
	if (!stack)
		return (len);
	tmp = stack->node;
	while (tmp)
	{
		tmp = tmp->next;
		len ++;
	}
	return (len);
}

void	free_stack(t_stack *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;

	if (!stack)
		return ;
	tmp = stack->node;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(stack);
}

t_stack_node	*node_new(int value, size_t chunk_n)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->chunk_n = chunk_n;
	node->next = NULL;
	return (node);
}
