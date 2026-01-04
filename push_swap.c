#include "push_swap.h"

void	log_tab(int *tab)
{
	while (*tab)
		printf("%i ",*tab);
}
int main(int ac, char **av)
{
	int inpcheck;
	int	*temp_stack;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		inpcheck = check_input(av[1]);

		if (inpcheck == -1)
		{
			write(1,"Error\n",ft_strlen("Error\n"));
			return (0);
		}
		temp_stack = (int *)malloc(sizeof(int) * count_input_elements(av[1]));
		if (!temp_stack)
			return (0);

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
