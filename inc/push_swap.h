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
# include "ft_printf.h"
# include <stdbool.h>

typedef struct s_intlist
{
	int					element;
	struct s_intlist	*prev;
	struct s_intlist	*next;
}						t_intlist;

typedef struct s_stacks
{
	t_intlist	*a;
	t_intlist	*head_a;
	t_intlist	*tail_a;
	t_intlist	*b;
	t_intlist	*head_b;
	t_intlist	*tail_b;
	int			len_a;
	int			len_b;
}				t_stacks;

typedef enum e_op_stack
{
	stack_a = 1,
	stack_b = -1,
	both = 0,
}	t_op_stack;

// probably just name it e_op
typedef enum e_op_name
{
	op_swap,
	op_push,
	op_rot,
	op_rrot,
}	t_op_name;

// Probably name it t_opc?
typedef struct s_opcount
{
	int	sa_count;
	int	sb_count;
	int	ss_count;
	int	pa_count;
	int	pb_count;
	int	ra_count;
	int	rb_count;
	int	rr_count;
	int	rra_count;
	int	rrb_count;
	int	rrr_count;
}		t_opcount;

/* 		Operations */
//typedef void	(*t_operation)(t_stacks *stacks);
void		do_op(t_stacks *stacks, t_op_name op, t_op_stack stack, int n);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

/*		Initialization and exit		*/
t_stacks	*allocate_stacks(int count);
void		fill_stack(t_stacks *stacks, int count, char **numbers);
void		free_exit(t_stacks *stacks, int error_check);
t_intlist	*add_node(int init_val);

/*		Wrappers		*/
/* t_intlist wrappers */
void		swap_nodes(t_intlist *node1, t_intlist *node2);
t_intlist	*get_element_n(t_stacks *stacks, t_op_stack stack, int n);
/*	t_opcount wrappers */
int			count_total(t_opcount opcount);
t_opcount	init_opcount(void);

/* 		Sorting functions	 */
void		select_cheapest_sort(t_stacks *stacks);
void		sort_small_stack(t_stacks *stacks, t_op_stack op_stack, int len);
void		sort_three(t_stacks *stacks, t_intlist *stack, t_op_stack a_b);

/*		For Select Cheapest Sort		*/
void		execute_operations(t_stacks *stacks, t_opcount ops, t_op_stack dst);
/*	counting operations	*/
int			count_rev_rots(t_intlist *node, const t_intlist *target);
int			count_obv_rots(t_intlist *node, const t_intlist *target);
t_opcount	count_rr(t_opcount opcount);
t_opcount	count_rrr(t_opcount opcount);
t_opcount	count_ra_rrb(t_opcount opcount);
t_opcount	count_rb_rra(t_opcount opcount);
t_opcount	find_smallest_opcount(t_opcount opc);
/*	determening and pushing cheapest candidate (b to a)*/
void		cheapest_to_a(t_stacks *stacks);
t_intlist	*find_cand_place_a(t_stacks *stacks, int cand_val, int len);
t_intlist	*find_cand_b(t_stacks *stacks, t_opcount *pot_opcount, int cur_tot);
t_opcount	check_cand_opcount_b(t_stacks *stacks, t_intlist *cand);
void		count_to_a(t_stacks *stacks, t_opcount *opc, t_intlist *cand);
void		count_from_b(t_intlist *b, t_opcount *opc, t_intlist *cand);
/*	determening and pushing cheapest candidate (a to b)*/
void		cheapest_to_b(t_stacks *stacks);
t_intlist	*find_cand_place_b(t_stacks *stacks, int cand_val, int len);
t_intlist	*find_cand_a(t_stacks *stacks, t_opcount *pot_opcount, int cur_tot);
t_opcount	check_cand_opcount_a(t_stacks *stacks, t_intlist *cand);
void		count_to_b(t_stacks *stacks, t_opcount *opc, t_intlist *cand);
void		count_from_a(t_intlist *a, t_opcount *opc, t_intlist *cand);

/* test functions (keep commented) */
//void	print_stack(t_intlist *stack, int len, char a_or_b, int with_prev_next);

#endif
