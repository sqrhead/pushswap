/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:37 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/13 18:55:16 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_single_input(char **av, long **temp_stack, int *n_elements)
{
	*n_elements = count_input_elements(av[1]);
	*temp_stack = (long *)malloc(sizeof(long) * *n_elements);
	if (!*temp_stack)
		return (1);
	if (parse_single_input(av[1], *temp_stack) == 1)
		return (1);
	return (0);
}

int	initialize_multi_input(int ac, char **av, long **temp_stack, int *n_elements)
{
	int result;

	result = 0;
	*n_elements = ac - 1;
	*temp_stack = (long *)malloc(sizeof(long) * *n_elements);
	if (!*temp_stack)
		return (1);
	result = parse_mul_input(av, *temp_stack, *n_elements);
	return (result);
}