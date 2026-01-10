#include "push_swap.h"

void	reverse_rotate_a(t_stack *stacka)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;
	t_stack_node	*tmp3;
	if (!stacka || !stacka->node)
		return;

	tmp = stacka->node;
	tmp2 = stacka->node;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp3 = tmp2->next;
	tmp2->next = NULL;
	stacka->node = tmp3;
	stacka->node->next = tmp;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stackb)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp2;
	t_stack_node	*tmp3;
	if (!stackb || !stackb->node)
		return;

	tmp = stackb->node;
	tmp2 = stackb->node;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp3 = tmp2->next;
	tmp2->next = NULL;
	stackb->node = tmp3;
	stackb->node->next = tmp;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack *stacka, t_stack *stackb)
{
	reverse_rotate_a(stacka);
	reverse_rotate_b(stackb);
	write(1, "rrr\n", 4);
}