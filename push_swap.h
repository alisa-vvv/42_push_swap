/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:33:13 by avaliull          #+#    #+#             */
/*   Updated: 2025/01/07 19:30:40 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include "libft_printf/ft_printf.h"

typedef struct	s_intlist
{
	int		element;
	struct s_intlist		*prev;
	struct s_intlist		*next;
}			t_intlist;

typedef struct	s_stacks
{
	t_intlist		*a;
	t_intlist		*b;
	int		len_a;
	int		len_b;
}			t_stacks;

/* t_intlist initialzation */
t_intlist	*add_node(int init_val);
void		free_node(t_intlist *node, int *len);
/* t_intlist wrappers */
void	swap_nodes(t_intlist *node1, t_intlist *node2);
t_intlist 	*get_element_n(t_intlist *node, int n);

/* t_stacks allocation and clearing */
t_stacks	*allocate_stacks(int count);
void		fill_stack(t_stacks *stacks, int count, char **numbers);
void		free_exit(t_stacks *stacks, int error_check);

/* swap actions */
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

/* test functions (keep commented) */
void	print_stack(t_intlist *stack, int len, char a_or_b, int with_prev_next);
void	do_n_times(t_stacks *stacks, void (*f)(t_stacks *stacks), int n);

#endif
