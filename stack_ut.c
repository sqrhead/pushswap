#include "push_swap.h"

void			stack_new_node(t_stack **stack, t_stack_node *node)
{	
	t_stack_node	*tmp;
	
	if (!stack)
	{
		printf("stack_not_found\n");
		*stack = (t_stack*)malloc(sizeof(t_stack));
		if (!*stack)
			return;
		(*stack)->node = node;
		(*stack)->node->next = NULL;
		return;
	}
	if (!(*stack)->node)
	{
		printf("NULL_NODE\n");
		return ;
	}
	tmp = (*stack)->node;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = node;	
}
t_stack_node	*stack_get_head(t_stack *stack)
{	
	t_stack_node *tmp;
	if (!stack)
		return (NULL);
	tmp = stack->node;
	while (tmp)
	{
		if (!tmp->next)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
int				stack_get_len(t_stack *stack)
{
	int	len;
	t_stack_node *tmp;

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
		return;
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
