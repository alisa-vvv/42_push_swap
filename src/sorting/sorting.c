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

//void	reverse_sort_three(t_stacks *stacks, t_intlist *sorted_stack)
//{
//	const int el1 = sorted_stack->element;
//	const int el2 = sorted_stack->next->element;
//	const int el3 = sorted_stack->prev->element;
//	
//	if (el1 > el2 && el2 < el3)
//		9 7 8
//	{
//		sorted_stack->sorted = true;
//		sorted_stack->prev->sorted = true;
//		sorted_stack->next->sorted = true;
//		return ;
//	}
//	if (el1 < el2 && el2 > el3)
//		7 9 8
//		do_op(stacks, op_rrot, a_b, 1);
//	if ((el1 > el2 && el2 > el3) || (el1 > el2 && el2 < el3 && el3 < el1))
//		9 8 7
//		do_op(stacks, op_rot, a_b, 1);
//	if ((el1 < el2 && el2 > el3 && el3 > el1) || (el1 > el2 && el2 > el3)
//			|| (el1 > el2 && el2 < el3 && el3 > el1))
//		do_op(stacks, op_swap, a_b, 1);
//	sorted_stack->sorted = true;
//	sorted_stack->prev->sorted = true;
//	sorted_stack->next->sorted = true;
//}
//
void	push_to_b(t_stacks *stacks)
{
//	print_stack(stacks->a, stacks->len_a, 'a', 0);
//	print_stack(stacks->b, stacks->len_b, 'b', 0);
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
	t_opcount	opcount;
	t_opcount	pot_opcount;
	t_intlist	*candidate;
	t_intlist	*pot_candidate;

	while (stacks->len_a > 3)
	{
		candidate = stacks->a;
		opcount = check_cand_opcount_a(stacks, candidate);
			//ft_printf("opcount before shenanigans: %d\n", count_total(opcount));
		pot_opcount = init_opcount();
		pot_candidate = find_cand_a(stacks, &pot_opcount, count_total(opcount));
		if (pot_candidate)
		{
			//ft_printf("opcount should be bigger: %d\n", count_total(opcount));
			//ft_printf("pot_opcount: %d\n", count_total(pot_opcount));
			opcount = pot_opcount;
//			candidate = pot_candidate; // this is only needed when testing
//			ft_printf("candidate: %d\n", candidate->element);
		}
		else 
		{
			//ft_printf("opcount should be smaller: %d\n", count_total(opcount));
			//ft_printf("pot_opcount: %d\n", count_total(pot_opcount));
		}
	//		ft_printf("candidate: %d\n", candidate->element);
		execute_operations(stacks, opcount, stack_b);
		if (stacks->b->element < stacks->head_b->element)
			stacks->head_b = stacks->b;
		if (stacks->b->element > stacks->tail_b->element)
			stacks->tail_b = stacks->b;
	}

	// this does not seem to improve the algo at all, might even be slightly worse
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

void	turk(t_stacks *stacks)
{
//	t_opcount	opcount;
//	t_opcount	pot_opcount;
//	t_intlist	*candidate;
//	t_intlist	*pot_candidate;

	push_to_b(stacks);
	sort_small_stack(stacks, stack_a, stacks->len_a);
	stacks->head_a = stacks->a;
	stacks->tail_a = stacks->a->prev;
//	while (stacks->len_b)
//	{
//		candidate = stacks->b;
//		opcount = check_cand_opcount_b(stacks, candidate);
//		pot_opcount = init_opcount();
//		pot_candidate = find_cand_b(stacks, &pot_opcount, count_total(opcount));
//		if (pot_candidate)
//			opcount = pot_opcount;
//		execute_operations(stacks, opcount, stack_a);
//		if (stacks->a->element < stacks->head_a->element)
//			stacks->head_a = stacks->a;
//		if (stacks->a->element > stacks->tail_a->element)
//			stacks->tail_a = stacks->a;
//	}
	t_intlist	*target;
	int			obv_rots;
	int			rev_rots;
//	print_stack(stacks->a, stacks->len_a, 'a', 0);
//	print_stack(stacks->b, stacks->len_b, 'b', 0);
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
	if (stacks->a != stacks->head_a)
		put_lowest_on_top(stacks);
//	print_stack(stacks->a, stacks->len_a, 'a', 0);
//	print_stack(stacks->b, stacks->len_b, 'b', 0);
}
