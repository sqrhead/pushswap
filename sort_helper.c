#include "push_swap.h"

void	rottotarget(t_stack **s, t_stack_node *t, int pos, int len)
{
	while ((*s)->node != t)
	{
		if (pos <= len / 2)
			rotate_a(*s);
		else
			reverse_rotate_a(*s);
	}
}
