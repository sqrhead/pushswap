/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:48:37 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/18 14:39:10 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_single_input(char **av, long **ts, int *nele)
{
	*nele = words_num(av[1], ' ');
	*ts = (long *)malloc(sizeof(long) * *nele);
	if (!*ts)
		return (1);
	if (parse_single_input(av[1], *ts, *nele) == 1)
		return (1);
	return (0);
}

int	initialize_multi_input(int ac, char **av, long **ts, int *nele)
{
	int	result;

	result = 0;
	*nele = ac - 1;
	*ts = (long *)malloc(sizeof(long) * *nele);
	if (!*ts)
		return (1);
	result = parse_mul_input(av, *ts, *nele);
	return (result);
}
