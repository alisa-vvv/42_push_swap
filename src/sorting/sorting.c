#include "push_swap.h"

void	execute_operations(t_stacks *stacks, t_opcount ops, e_op_stack dst)
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

void	push_to_b(t_stacks *stacks)
{
//	print_stack(stacks->a, stacks->len_a, 'a', 0);
//	print_stack(stacks->b, stacks->len_b, 'b', 0);
	do_op(stacks, op_push, stack_b, stacks->len_a - 3);
	if (stacks->len_a <= 3)
		sort_small_stack(stacks, stack_a, stacks->len_a);
	stacks->head_a = stacks->a;
	stacks->tail_a = stacks->a->prev;
//	do_op(stacks, op_push, stack_b, 2);
//	if (stacks->b < stacks->b->next)
//	{
//		stacks->head_b = stacks->b;
//		stacks->tail_b = stacks->b->next;
//	}
//	else
//	{
//		stacks->head_b = stacks->b->next;
//		stacks->tail_b = stacks->b;
//	}
}

void	turk(t_stacks *stacks)
{
	t_opcount	opcount;
	t_opcount	pot_opcount;
	t_intlist	*candidate;
	t_intlist	*pot_candidate;

	push_to_b(stacks);
	while (stacks->len_b)
	{
		candidate = stacks->b;
		opcount = check_cand_opcount_b(stacks, candidate);
		pot_opcount = init_opcount();
		pot_candidate = find_cand_b(stacks, &pot_opcount, count_total(opcount));
		if (pot_candidate)
			opcount = pot_opcount;
		execute_operations(stacks, opcount, stack_a);
		if (stacks->a->element < stacks->head_a->element)
			stacks->head_a = stacks->a;
		if (stacks->a->element > stacks->tail_a->element)
			stacks->tail_a = stacks->a;
	}
	if (stacks->a != stacks->head_a)
		put_lowest_on_top(stacks);
}
