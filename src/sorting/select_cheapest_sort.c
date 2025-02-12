/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   select_cheapest_sort.c                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: avaliull <avaliull@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/11 15:17:39 by avaliull     #+#    #+#                  */
/*   Updated: 2025/02/12 13:05:19 by avaliull     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_operations(t_stacks *stacks, t_opcount ops, t_op_stack dst)
{
	if (ops.rr_count)
		do_op(stacks, op_rot, both, ops.rr_count);
	if (ops.rrr_count)
		do_op(stacks, op_rrot, both, ops.rrr_count);
	if (ops.ra_count)
		do_op(stacks, op_rot, stack_a, ops.ra_count);
	if (ops.rb_count)
		do_op(stacks, op_rot, stack_b, ops.rb_count);
	if (ops.rra_count)
		do_op(stacks, op_rrot, stack_a, ops.rra_count);
	if (ops.rrb_count)
		do_op(stacks, op_rrot, stack_b, ops.rrb_count);
	do_op(stacks, op_push, dst, 1);
}

static void	put_lowest_on_top(t_stacks *stacks)
{
	int	obv_count;
	int	rev_count;

	obv_count = count_obv_rots(stacks->a, stacks->head_a);
	rev_count = count_rev_rots(stacks->a, stacks->head_a);
	if (obv_count < rev_count)
		do_op (stacks, op_rot, stack_a, obv_count);
	else
		do_op (stacks, op_rrot, stack_a, rev_count);
}

static void	put_biggest_on_top(t_stacks *stacks)
{
	int	obv_rots;
	int	rev_rots;

	while (stacks->b != stacks->tail_b)
	{
		obv_rots = count_obv_rots(stacks->b, stacks->tail_b);
		rev_rots = count_rev_rots(stacks->b, stacks->tail_b);
		if (obv_rots < rev_rots)
			do_op(stacks, op_rot, stack_b, obv_rots);
		else
			do_op(stacks, op_rrot, stack_b, rev_rots);
	}
}

static void	push_to_b(t_stacks *stacks)
{
	do_op(stacks, op_push, stack_b, 2);
	if (stacks->b->element < stacks->b->next->element)
	{
		stacks->head_b = stacks->b;
		stacks->tail_b = stacks->b->next;
	}
	else
	{
		stacks->head_b = stacks->b->next;
		stacks->tail_b = stacks->b;
	}
	cheapest_to_b(stacks);
}

void	select_cheapest_sort(t_stacks *stacks)
{
	push_to_b(stacks);
	if (stacks->b != stacks->head_b)
		put_biggest_on_top(stacks);
	sort_small_stack(stacks, stack_a, stacks->len_a);
	stacks->head_a = stacks->a;
	stacks->tail_a = stacks->a->prev;
	cheapest_to_a(stacks);
	if (stacks->a != stacks->head_a)
		put_lowest_on_top(stacks);
}
