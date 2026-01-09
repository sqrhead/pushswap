/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshelna <fshelna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:51:54 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/09 12:18:18 by fshelna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_stack_node
{
	int					value;
	size_t				chunk_n;
	struct s_stack_node	*next;
} t_stack_node;

typedef struct s_stack
{
	struct s_stack_node		*node;
} t_stack;

// utilities
int		ft_strlen(const char *str);
long	ft_atol(char *str);
int		ft_isdigit(char c);
int		ft_isspace(char c);
int		ft_issign(char c);

int		word_len(const char *str, char c);
int		words_num(const char *s, char c);
char	**free_pp(char **split);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
// input check
int		check_input(char *str);
int		count_input_elements(char *str);
int		parse_single_input(char *str, long *tab);
int		parse_mul_input(char *str, long *tab);
// stack
void			stack_new_node(t_stack **stack, t_stack_node *node);
t_stack_node	*stack_get_head(t_stack *stack);
t_stack_node	*node_new(int value, size_t chunk_n);
int				stack_get_len(t_stack *stack);
void			free_stack(t_stack *stack);
void			stack_pop(t_stack *stack);

// commands
void	swap_a(t_stack *stacka); // swap first 2 elements on stack 'a', nothing if one or less
void	swap_b(t_stack *stackb); // same for b
void	swap_both(t_stack *stacka, t_stack *stackb); // both of them
void	push_a(t_stack *stacka, t_stack *stackb); // first element from 'b' to 'a'
void	push_b(t_stack *stacka, t_stack *stackb); // first element from 'a' to 'b'
void	rotate_a(t_stack *stacka); // shift up, first become last
void	rotate_b(t_stack *stackb);
void	rotate_both(t_stack *stacka, t_stack *stackb);
void	reverse_rotate_a(t_stack *stacka); // shift down, last become first
void	reverse_rotate_b(t_stack *stackb);
void	reverse_rotate_both(t_stack *stacka, t_stack *stackb);

#endif
