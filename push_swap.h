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
# include <stdbool.h>

typedef struct	s_intlist
{
	int					element;
	bool				sorted;
	struct s_intlist	*prev;
	struct s_intlist	*next;
}			t_intlist;

typedef struct	s_stacks
{
	t_intlist		*a;
	t_intlist		*b;
	//t_intlist		*sorted_top_a;
	//t_intlist		*sorted_top_b;
	int		len_a;
	int		len_b;
}			t_stacks;

typedef struct	s_med_arrs
{
	int	*elems;
	int	*lows;
	int	*highs;
}		t_med_arrs;

typedef enum	rot_dir
{
	obverse = 1,
	reverse = 0,
}	e_rot_dir;

typedef enum	op_stack
{
	stack_a = 1,
	stack_b = -1,
	both = 0,
}	e_op_stack;

typedef enum	op_name
{
		op_swap,
		op_push,
		op_rot,
		op_rrot,
}		e_op_name;

typedef void	(*operation)(t_stacks *stacks);

//typedef struct	s_opcount
//{
//	int	sa_count;
//	int	sb_count;
//	int	ss_count;
//	int	pa_count;
//	int	pb_count;
//	int	ra_count;
//	int	rb_count;
//	int	rr_count;
//	int	rra_count;
//	int	rrb_count;
//	int	rrr_count;
//}		t_opcount;

/* t_intlist initialzation */
t_intlist	*add_node(int init_val);
void		free_node(t_intlist *node, int *len);
/* t_intlist wrappers */
void	swap_nodes(t_intlist *node1, t_intlist *node2);
t_intlist 	*get_element_n(t_stacks *stacks, e_op_stack stack, int n);

/* t_stacks allocation and clearing */
t_stacks	*allocate_stacks(int count);
void		fill_stack(t_stacks *stacks, int count, char **numbers);
void		free_exit(t_stacks *stacks, int error_check);

/* sorting */
void	put_part_on_arr(t_med_arrs *med_arrs, t_intlist *top_node, int count);
t_med_arrs *free_med_arrs(t_med_arrs *med_arrs);
t_med_arrs	*alloc_med_arrs(t_intlist *top_node, int count);
int	find_median(t_med_arrs *arrs, const int len, const int med_pos);
void	sort_small_stack(t_stacks *stacks, e_op_stack op_stack, int len);
void	sort_three(t_stacks *stacks, t_intlist *sorted_stack, e_op_stack a_b);
void	quicksort(t_stacks *stacks);

/* operations */
void	do_op(t_stacks *stacks, e_op_name op, e_op_stack stack, int n);
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
