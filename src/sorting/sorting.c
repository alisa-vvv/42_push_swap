#include "push_swap.h"

void	put_lowest_on_top(t_stacks *stacks)
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

void	put_biggest_on_top(t_stacks *stacks)
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

void	cheapest_to_b(t_stacks *stacks)
{
	t_opcount	opcount;
	t_opcount	pot_opcount;
	t_intlist	*candidate;
	t_intlist	*pot_candidate;

	while (stacks->len_a > 3)
	{
		candidate = stacks->a;
		opcount = check_cand_opcount_a(stacks, candidate);
		pot_opcount = init_opcount();
		pot_candidate = find_cand_a(stacks, &pot_opcount, count_total(opcount));
		if (pot_candidate)
			opcount = pot_opcount;
		execute_operations(stacks, opcount, stack_b);
		if (stacks->b->element < stacks->head_b->element)
			stacks->head_b = stacks->b;
		if (stacks->b->element > stacks->tail_b->element)
			stacks->tail_b = stacks->b;
	}
}

void	push_to_b(t_stacks *stacks)
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

void	cheapest_to_a(t_stacks *stacks)
{
	t_intlist	*target;
	int			obv_rots;
	int			rev_rots;

	while (stacks->len_b)
	{
		target = find_cand_place_a(stacks, stacks->b->element, stacks->len_a);
		obv_rots = count_obv_rots(stacks->a, target);
		rev_rots = count_rev_rots(stacks->a, target);
		if (obv_rots < rev_rots)
		 	do_op(stacks, op_rot, stack_a, obv_rots);
		else
			do_op(stacks, op_rrot, stack_a, rev_rots);
		do_op(stacks, op_push, stack_a, 1);
		if (stacks->a->element < stacks->head_a->element)
			stacks->head_a = stacks->a;
		if (stacks->a->element > stacks->tail_a->element)
			stacks->tail_a = stacks->a;
	}
}

void	turk(t_stacks *stacks)
{
	push_to_b(stacks);
	if (stacks->b != stacks->head_b)
		put_biggest_on_top(stacks);
	sort_three(stacks, stacks->a, stacks->len_a);
	stacks->head_a = stacks->a;
	stacks->tail_a = stacks->a->prev;
	cheapest_to_a(stacks);
	if (stacks->a != stacks->head_a)
		put_lowest_on_top(stacks);
}
