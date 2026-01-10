/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:54:39 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/10 21:31:17 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void log_stack(t_stack *stack, char ws)
{
	printf("***** STACK [%c]************************\n",ws);
	t_stack_node *tmp;
	tmp = stack->node;
	while (tmp)
	{
		printf("value : [ %i ] chunk_n : [ %ld ]\n",tmp->value, tmp->chunk_n);
		// printf("chunk:%zu\n",tmp->chunk_n);
		tmp = tmp->next;
	}
}
// TODO :
// If space at the end of input, a 0 is given to the *temp_stack
int main(int ac, char **av)
{
	long	*temp_stack;
	t_stack *stacka;
	t_stack *stackb;

	stacka  = (t_stack *)malloc(sizeof(t_stack));
	stackb  = (t_stack *)malloc(sizeof(t_stack));
	if (!stacka || !stackb)
		return (0);
	stacka->node = NULL;
	stackb->node = NULL;


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
	if (check_duplicate(temp_stack,n_elements) == 1)
	{
		printf("Error: duplicate\n");
		free_pp(div);
		free(temp_stack);
		return (0);
	}
	index = 0;
	while (index < n_elements)
	{
		stack_new_node(&stacka, node_new((int)temp_stack[n_elements - index - 1],0));
		index ++;
	}
	int len_stack = stack_get_len(stacka);
	printf("stacka len:%i\n", len_stack);
	printf("*** TOP_STACK_VALUE : %i\n",stacka->node->value);
	log_tab(temp_stack, n_elements);
	bubble_sort(temp_stack, n_elements);
	log_tab(temp_stack, n_elements);
	generate_chunks(temp_stack, &stacka);
	log_stack(stacka, 'A');

	if (stacka != NULL)
	{
		printf("********* STACK_FREED *******************\n");
		// log_stack(stacka);
		free_stack(stacka);
	}
	// free_stack(stack_b);
	free_pp(div);
	free(temp_stack);
	return (0);
}
