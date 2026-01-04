#include "push_swap.h"


int main(int ac, char **av)
{
	int inpcheck;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		inpcheck = check_input(av[1]);
		if (inpcheck == -1)
		{
			write(1,"Error\n",ft_strlen("Error\n"));
		}
	}
	else
	{
		while(ac - 1 > 0)
		{
			inpcheck = check_input(av[ac - 1]);
			ac --;
			if (inpcheck == -1)
			{
				write(1,"Error\n",ft_strlen("Error\n"));
			}
		}
	}
}
