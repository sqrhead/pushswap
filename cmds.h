#ifndef CMDS_H
#define CMDS_H

int	get_ilen(int *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len ++;
		s ++;
	}
	return (len);
}
void	sa(int *sa)
{
	int	temp;
	int	len;
	if (!sa || get_ilen(sa) < 2)
		return;
	len = get_ilen(sa);
	temp = sa[len - 1];
	sa[len - 1] = sa[len -2];
	sa[len - 2] = temp;
	write(1,"sa\n",3);
}
void	sb(int *sb)
{
	int	temp;
	int	len;
	if (!sb || get_ilen(sb) < 2)
		return;
	len = get_ilen(sb);
	temp = sb[len - 1];
	sb[len - 1] = sb[len -2];
	sb[len - 2] = temp;
	write(1,"sb\n",3);

}
void	ss(int *stack_a, int *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
void	pa(int *sa, int *sb)
{

	if (!sb || !sa || get_ilen(sb) < 1)
		return;
	while (*sa)
		sa ++;
	while (*sb)
		sb ++;
	sb --;
	*sa = *sb;
	*sb = 0;
	write(1,"pa\n",3);

}
void	pb(int *sa, int *sb)
{
	if (!sb || !sa || get_ilen(sa) < 1)
		return;
	while (*sa)
		sa ++;
	while (*sb)
		sb ++;
	sa --;
	*sb = *sa;
	*sa = 0;
	write(1,"pb\n",3);
}

void	ra(int *sa)
{
	int	tmp_one;
	int	tmp_two;
	int	len;
	int	index;

	len = get_ilen(sa);
	tmp_two = sa[len - 1]
	index = 0;
	while (index < len - 1)
	{
	}
}
#endif
