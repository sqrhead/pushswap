#include "push_swap.h"


void	push_a(t_stack *stacka, t_stack *stackb)
{
	t_stack_node	*tmp;
	if (!stackb || !stacka)
		return;
	if (stack_get_len(stackb) < 1)
		return;
	tmp = stackb->node->next;
	stack_new_node(&stacka, stackb->node);
	stackb->node = tmp;
	write(1,"pa\n",3);
}

void	push_b(t_stack *stacka, t_stack *stackb)
{
	t_stack_node	*tmp;
	if (!stackb || !stacka)
		return;
	if (stack_get_len(stacka) < 1)
		return;
	tmp = stacka->node->next;
	stack_new_node(&stackb, stacka->node);
	stacka->node = tmp;
	write(1,"pb\n",3);
}