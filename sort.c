#include "push_swap.h"

void	bubble_sort(long *tab, int len)
{
	int 	i;
	int 	j;
    int	 	swapped;
	long	tmp;

	i = 0;
	j = 0;
	swapped = 0;
    while (i < len - 1)
	{
		j = 0;
		swapped = 1;
		while (j < len - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				swapped = 0;
			}
			j ++;
		}
		i ++;
		if (swapped == 1)
			break;
	}
}

