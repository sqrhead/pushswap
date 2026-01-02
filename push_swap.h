#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

typedef struct s_node
{
	long	value;
	int		indexv;
} t_node;

// utilities
int		ft_strlen(const char *str);
long	ft_atol(char *str);
int		ft_isdigit(char c);
// input check
int		check_input(char *str);

// commands
void	swap_a(t_list *stacka); // swap first 2 elements on stack 'a', nothing if one or less
void	swap_b(t_list *stackb); // same for b
void	swap_both(t_list *stack, t_list *stackb); // both of them
void	push_a(); // first element from 'b' to 'a'
void	push_b(); // first element from 'a' to 'b'
void	rotate_a(); // shift up, first become last
void	rotate_b();
void	rotate_both();
void	reverse_rotate_a(); // shift down, last become first
void	reverse_rotate_b();
void	reverse_rotate_both();

/*
 * 	a | b
 * 	0
 * 	-1
 *	1
 * */

#endif
