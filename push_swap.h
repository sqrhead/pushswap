#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


typedef struct s_stack_node
{
	int	value;
	int	position;
	int	destination;

} t_stack_node;

typedef struct s_stack
{
	struct s_stack_node	*node;
	struct s_stack 		*next;

} t_stack;

typedef struct s_chunk
{
	int		*values;
} t_chunk;

// utilities
int		ft_strlen(const char *str);
long	ft_atol(char *str);
int		ft_isdigit(char c);
int		ft_isspace(char c);
// input check
int		check_input(char *str);

// stack utils
void	pop(t_stack *stack);
void	push(t_stack *stack);
// commands
void	swap_a(t_stack *stacka); // swap first 2 elements on stack 'a', nothing if one or less
void	swap_b(t_stack *stackb); // same for b
void	swap_both(t_stack *stack, t_stack *stackb); // both of them
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
