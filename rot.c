#include "push_swap.h"

void	rotate_a(t_stack *stacka)
{	
	t_stack_node	*tmp;
	t_stack_node	*tmp2;
	if (!stacka || !stacka->node)
		return;

	tmp = stacka->node;
	stacka->node = stacka->node->next;
	tmp2 = stacka->node;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	tmp2->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stackb)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;
	if (!stackb || !stackb->node)
		return;

	tmp = stackb->node;
	stackb->node = stackb->node->next;
	tmp2 = stackb->node;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
	tmp2->next->next = NULL;
	write(1," ra\n", 3);
}

void	rotate_both(t_stack *stacka, t_stack *stackb)
{
	rotate_a(stacka);
	rotate_b(stackb);
}