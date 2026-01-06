/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:54:39 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/06 20:45:37 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	log_tab(long *tab, int size)
{
	int index = 0;

	while (index < size)
	{
		printf("tab element:%ld\n",tab[index]);
		index ++;
	}

}

void log_str(char **str)
{
	while (*str)
	{
		printf("splitted:%s\n",*str);
		str ++;
	}
}

// void bubble_sort(int *tab, int size)
// {
// 	int index = 0;
// 	int temp = 0;

// 	while (index < size)
// 	{

// 	}
// }

int main(int ac, char **av)
{
	long	*temp_stack;

	int n_elements = count_input_elements(av[1]);
	printf("elements number : %i\n",n_elements);
	temp_stack = (long *)malloc(sizeof(long) * n_elements);
	if (!temp_stack)
	{
		printf("Failed malloc\n");
		return (0);
	}
	char **div = ft_split(av[1],' ');
	log_str(div);
	int index = 0;
	while (div[index])
	{
		temp_stack[index] = ft_atol(div[index]);
		index ++;
	}
	log_tab(temp_stack,n_elements);

	free_pp(div);
	free(temp_stack);
}
