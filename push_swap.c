/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:54:39 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/08 12:15:10 by fshelna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "cmds.h"

static void	log_tab(long *tab, int size)
{
	int index = 0;
	printf("\n==== LONG_TAB ================================\n");
	while (index < size)
	{
		printf("tab element:%ld\n",tab[index]);
		index ++;
	}
	printf("\n==============================================\n");
}
static void	log_itab(int *tab, int size)
{
	int index = 0;
	printf("\n=== INT_TAB =================================\n");
	while (index < size)
	{
		printf("tab element:%d\n",tab[index]);
		index ++;
	}
	printf("\n=============================================\n");

}
void log_str(char **str)
{
	printf("\n==== SPLITTED =========================================\n");
	while (*str)
	{
		printf("split element:%s\n",*str);
		str ++;
	}
	printf("\n=======================================================\n");
}
void log_stack(t_stack *stack)
{
	t_stack_node *tmp;
	tmp = stack->node;
	while (tmp)
	{
		printf("value:%i\n",tmp->value);
		printf("chunk:%zu\n",tmp->chunk_n);
		tmp = tmp->next;
	}
}
//  negative numbers problem
int	check_duplicate(long *tab, int size)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (index < size)
	{
		j = 0;
		while (j < size)
		{
			if (index != j && tab[index] == tab[j])
				return (1);
			j ++;
		}
		index ++;
	}
	return (0);
}
// TODO :
// If space at the end of input, a 0 is given to the *temp_stack
int main(int ac, char **av)
{
	long	*temp_stack;
	int	*stack_a;
	int	*stack_b;
	t_stack *stacka;
	t_stack *stackb;

	stacka = NULL;
	stackb = NULL;
	if (ac < 2) // No Input
	{
		printf("Error: no elements passed\n");
		return (0);
	}
	if (check_input(av[1]) == 1) // Input not valid 
	{
		return (0);
	}
	int n_elements = count_input_elements(av[1]);
	printf("elements number : %i\n",n_elements);
	temp_stack = (long *)malloc(sizeof(long) * n_elements);
	if (!temp_stack)
	{
		printf("Failed malloc\n");
		return (0);
	}
	char **div = ft_split(av[1],' ');
//	log_str(div);
	int index = 0;
	while (div[index])
	{
		temp_stack[index] = ft_atol(div[index]);
		if (temp_stack[index] > INT_MAX || temp_stack[index] < INT_MIN)
		{
			printf("Error: OVERFLOW || UNDERFLOW\n");
			free_pp(div);
			free(temp_stack);
			return (0);
		}
		index ++;
	}
//	log_tab(temp_stack, n_elements);
	if (check_duplicate(temp_stack,n_elements) == 1)
	{
		printf("Error: duplicate\n");
		free_pp(div);
		free(temp_stack);
		return (0);
	}
	// sort here && check for duplicates
	// create stacks
	stack_a = (int *)malloc(sizeof(int) * n_elements);
	stack_b = (int *)malloc(sizeof(int) * n_elements);
	if (!stack_a || !stack_b)
		return (0);
	index = 0;
	while (index < n_elements)
	{
		stack_a[index] = temp_stack[n_elements - index - 1];
		index ++;
	}
	log_tab(temp_stack, n_elements);
	log_str(div);

	stack_new_node(&stacka, node_new(10,0));
	if (stacka != NULL)
	{
		log_stack(stacka);
		free_stack(stacka);
	}
	// free_stack(stack_b);
	free_pp(div);
	free(temp_stack);
	return (0);
}
