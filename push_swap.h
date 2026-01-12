/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:51:54 by fshelna           #+#    #+#             */
/*   Updated: 2026/01/12 21:26:13 by sqrhead          ###   ########.fr       */
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
	size_t				index;
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
int		check_duplicate(long *tab, int size);
int		check_input(char *str);
int		count_input_elements(char *str);
int		parse_single_input(char *str, long *tab);
int		parse_mul_input(char *str, long *tab);
// stack
void			stack_new_node(t_stack **stack, t_stack_node *node);
t_stack_node	*node_new(int value, size_t chunk_n);
t_stack_node	*stack_get_head(t_stack *stack);
int				stack_get_len(t_stack *stack);
void			stack_pop(t_stack *stack);
void			free_stack(t_stack *stack);
t_stack_node	*get_node(t_stack *stack, size_t index);
int				stack_is_sorted(t_stack *stack);
size_t			get_index(t_stack *stack, int value);
// chunk
void	generate_chunks(long *tab, t_stack **stack);
int		chunk_get_size(int stack_size);
int		chunk_contain(int chunk_n, t_stack *stack);

// sort
void	bubble_sort(long *tab, int len);
void 	sort_three(t_stack **stack);
void	sort_five(t_stack **stacka, t_stack **stackb);
void	mega_sort(t_stack *stacka, t_stack *stackb, long *temp_stack, int n_elements);
void	sort_high(t_stack *stacka, t_stack *stackb, int chunk_size, int chunk_index);
void	sort_low(t_stack *stacka, t_stack *stackb, int n_elements);

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
