#include "push_swap.h"

int	count_total(t_opcount opcount)
{
	int	total;

	total = 0;
	total += opcount.sa_count;
	total += opcount.sb_count;
	total += opcount.ss_count;
	total += opcount.pa_count;
	total += opcount.pb_count;
	total += opcount.ra_count;
	total += opcount.rb_count;
	total += opcount.rr_count;
	total += opcount.rra_count;
	total += opcount.rrb_count;
	total += opcount.rrr_count;
	return (total);
}

t_opcount	init_opcount(void)
{
	t_opcount	opcount;

	opcount.sa_count = 0;
	opcount.sb_count = 0;
	opcount.ss_count = 0;
	opcount.pa_count = 1;
	opcount.pb_count = 0;
	opcount.ra_count = 0;
	opcount.rb_count = 0;
	opcount.rr_count = 0;
	opcount.rra_count = 0;
	opcount.rrb_count = 0;
	opcount.rrr_count = 0;

	return (opcount);
}

// i think this is wrong
// I don;t think this is wrong
t_intlist *find_cand_place(t_stacks *stacks, int cand_val, int len)
{
	t_intlist	*cur_node;

	if (cand_val < stacks->head_a->element || cand_val > stacks->tail_a->element)
	{
		ft_printf("el is top or bot\n");
		ft_printf("and the value is: %d\n", stacks->head_a->element);
		return (stacks->head_a);
	}
	ft_printf("head_a: %d\n", stacks->head_a->element);
	ft_printf("tail_a: %d\n", stacks->tail_a->element);
	cur_node = stacks->head_a;
	while (len--)
	{
		if (cand_val < cur_node->element)
			break ;
		cur_node = cur_node->next;
	}
	ft_printf("candidate val is: %d\n", cand_val);
	ft_printf("candidate place is: %d\n", cur_node->element);
	return (cur_node);
}

int	count_rev_rots(t_intlist *node, const t_intlist *target)
{
	int	count;

	count = 0;
	while (node != target)
	{
		count++;
		node = node->prev;
	}
	return (count);
}
	
int	count_obv_rots(t_intlist *node, const t_intlist *target)
{
	int	count;

	count = 0;
	while (node != target)
	{
		count++;
		node = node->next;
	}
	return (count);
}

t_opcount	count_rr(t_opcount opcount)
{
	t_opcount	rr_opcount;

	rr_opcount = init_opcount();
	while (opcount.ra_count && opcount.rb_count)
	{
		opcount.ra_count--;
		opcount.rb_count--;
		rr_opcount.rr_count++;
	}
	rr_opcount.ra_count = opcount.ra_count;
	rr_opcount.rb_count = opcount.rb_count;
//	if (opcount.ra_count && opcount.rb_count)
//	{
//		if (opcount.ra_count > opcount.rb_count)
//		{
//			rr_opcount.rr_count = opcount.rb_count;
//			rr_opcount.ra_count = opcount.ra_count - opcount.rb_count;
//		}
//		else if (opcount.rb_count > opcount.ra_count)
//		{
//			rr_opcount.rr_count = opcount.ra_count;
//			rr_opcount.rb_count = opcount.rb_count - opcount.ra_count;
//		}
//		else
//			rr_opcount.rr_count = opcount.ra_count;
//	}
	return (rr_opcount);
}

t_opcount	count_rrr(t_opcount opcount)
{
	t_opcount	rrr_opcount;

	rrr_opcount = init_opcount();
	while (opcount.rra_count && opcount.rrb_count)
	{
		opcount.rra_count--;
		opcount.rrb_count--;
		rrr_opcount.rrr_count++;
	}
	rrr_opcount.rra_count = opcount.rra_count;
	rrr_opcount.rrb_count = opcount.rrb_count;
//	if (opcount.rra_count && opcount.rrb_count)
//	{
//		if (opcount.rra_count > opcount.rrb_count)
//		{
//			rrr_opcount.rrr_count = opcount.rrb_count;
//			rrr_opcount.rra_count = opcount.rra_count - opcount.rrb_count;
//		}
//		else if (opcount.rrb_count > opcount.rra_count)
//		{
//			rrr_opcount.rrr_count = opcount.rra_count;
//			rrr_opcount.rrb_count = opcount.rrb_count - opcount.rra_count;
//		}
//		else
//			rrr_opcount.rrr_count = opcount.rra_count;
//	}
	return (rrr_opcount);
}

t_opcount	count_ra_rrb(t_opcount opcount)
{
	t_opcount	ra_rrb_opcount;

	ra_rrb_opcount = init_opcount();
	ra_rrb_opcount.ra_count = opcount.ra_count;
	ra_rrb_opcount.rrb_count = opcount.rrb_count;
	return (ra_rrb_opcount);
}

t_opcount	count_rb_rra(t_opcount opcount)
{
	t_opcount	rb_rra_count;

	rb_rra_count = init_opcount();
	rb_rra_count.rb_count = opcount.rb_count;
	rb_rra_count.rra_count = opcount.rra_count;
	return (rb_rra_count);
}

void	count_a(t_stacks *stacks, t_opcount *opc, t_intlist *cand)
{
	t_intlist	*cand_place;

	cand_place = find_cand_place(stacks, cand->element, stacks->len_a);
	opc->ra_count = count_obv_rots(stacks->a, cand_place);
	opc->rra_count = count_rev_rots(stacks->a, cand_place);
}

void	count_b(t_intlist *b, t_opcount *opc, t_intlist *cand)
{
	opc->rb_count = count_obv_rots(b, cand);
	opc->rrb_count = count_obv_rots(b, cand);
}

t_opcount	find_smallest_opcount(t_opcount opc)
{
	t_opcount	rr;
	t_opcount	rrr;
	t_opcount	ra_rrb;
	t_opcount	rb_rra;
	t_opcount	smallest;

	rr = count_rr(opc);
	rrr = count_rrr(opc);
	ra_rrb = count_ra_rrb(opc);
	rb_rra = count_rb_rra(opc);
	if (count_total(rr) > 1)
		smallest = rr;
	if (count_total(rr) > count_total(rrr) && count_total(rrr) > 1)
		smallest = rrr;
	if (count_total(rrr) > count_total(ra_rrb) && count_total(ra_rrb) > 1)
		smallest = ra_rrb;
	if (count_total(ra_rrb) > count_total(rb_rra) && count_total(rb_rra) > 1)
		smallest = rb_rra;
	if (count_total(rr) == 1 && count_total(rrr) == 1 && count_total(ra_rrb) == 1
		&& count_total(rb_rra) == 1)
		return (init_opcount());
	return (smallest);
}

t_opcount	check_cand_opcount(t_stacks *stacks, t_intlist *cand)
{
	t_opcount	pot_opcount;

	pot_opcount = init_opcount();
	count_a(stacks, &pot_opcount, cand);
	count_b(stacks->b, &pot_opcount, cand);
	pot_opcount = find_smallest_opcount(pot_opcount);
	return (pot_opcount);
}

// in some cases, this appears to return the wrong pointer after finding the candidate.
// the logic of finding the candidate and counting steps appers to be correct, the return
// value appears to be wrong
// I think the candidate might be correct actually, seems more like the popcount will change
// while the pot_candidate remains the same. this can be fixed by splitting it into two
// functions and using local values in loop and only returning/dereferencing *pot_opcount
// and *pot_candidate when a new candidate is found. current version will return new_candidate
// , but the pot_opcount might be of a different (later) candidate. one such error will cascade
// and cause all further operatiosn to be incorrect.
// just fix it dumbass
t_intlist *find_cand(t_stacks *stacks, t_opcount *pot_opcount, int cur_tot)
{
	int			steps;
	t_intlist	*pot_candidate;
	t_intlist	*new_candidate;
	int			pot_tot;

	if (cur_tot <= stacks->len_b)
		steps = cur_tot;
	else
		steps = stacks->len_b;
	new_candidate = NULL;
	pot_candidate = stacks->b;
	while (steps-- > 0)
	{
		pot_candidate = pot_candidate->next;
		*pot_opcount = check_cand_opcount(stacks, pot_candidate);
		pot_tot = count_total(*pot_opcount);
		if (pot_tot < cur_tot)
		{
			steps -= (cur_tot - pot_tot);
			new_candidate = pot_candidate;
		}
	}
	pot_candidate = stacks->b;
	if (new_candidate)
		cur_tot = pot_tot;
	if (cur_tot <= stacks->len_b)
		steps = cur_tot;
	else
		steps = stacks->len_b;
	while (steps-- > 0)
	{
		pot_candidate = pot_candidate->prev;
		*pot_opcount = check_cand_opcount(stacks, pot_candidate);
		pot_tot = count_total(*pot_opcount);
		if (pot_tot < cur_tot)
		{
			steps -= (cur_tot - pot_tot);
			new_candidate = pot_candidate;
		}
	}
	return (new_candidate);
}

void	execute_operations(t_stacks *stacks, t_opcount ops)
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
	do_op(stacks, op_push, stack_a, 1);
}

void	turk(t_stacks *stacks)
{
	t_opcount	opcount;
	t_opcount	pot_opcount;
	t_intlist	*candidate;
	t_intlist	*pot_candidate;

	do_op(stacks, op_push, stack_b, stacks->len_a - 1);
	stacks->head_a = stacks->a;
	stacks->tail_a = stacks->a;
	while (stacks->len_b)
	{
		candidate = stacks->b;
		opcount = check_cand_opcount(stacks, candidate);
		pot_opcount = init_opcount();
		pot_candidate = find_cand(stacks, &pot_opcount, count_total(opcount));
		if (pot_candidate)
		{
			candidate = pot_candidate;
			opcount = pot_opcount;
		}
		ft_printf("is this candidate wrong? %d\n", candidate->element);
		execute_operations(stacks, opcount);
		if (stacks->a->element < stacks->head_a->element)
			stacks->head_a = stacks->a;
		if (stacks->a->element > stacks->tail_a->element)
			stacks->tail_a = stacks->a;
		print_stack(stacks->a, stacks->len_a, 'a', 1);
		print_stack(stacks->b, stacks->len_b, 'b', 1);
	}
	ft_printf("head a: %d\n", stacks->head_a->element);
	ft_printf("tail a: %d\n", stacks->tail_a->element);
}
