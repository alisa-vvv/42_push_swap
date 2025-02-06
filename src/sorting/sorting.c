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
	opcount.pa_count = 0;
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
		return (stacks->head_a);
	}
	cur_node = stacks->head_a;
	while (len--)
	{
		if (cand_val < cur_node->element)
			break ;
		cur_node = cur_node->next;
	}
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
	opc->rrb_count = count_rev_rots(b, cand);
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
	smallest = rr;
	if (count_total(smallest) > count_total(rrr))
		smallest = rrr;
	if (count_total(smallest) > count_total(ra_rrb))
		smallest = ra_rrb;
	if (count_total(smallest) > count_total(rb_rra))
		smallest = rb_rra;
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

int	cand_rev(t_stacks *stacks, t_opcount *opc, t_intlist **cand, int tot)
{
	int			steps;
	t_intlist	*tmp_cand;
	t_opcount	tmp_opcount;
	int			pot_tot;

	if (tot <= stacks->len_b)
		steps = tot;
	else
		steps = stacks->len_b;
	tmp_cand = stacks->b;
	while (steps-- > 0)
	{
		tmp_cand = tmp_cand->prev;
		tmp_opcount = check_cand_opcount(stacks, tmp_cand);
		pot_tot = count_total(tmp_opcount);
		if (pot_tot < tot)
		{
			steps -= (tot - pot_tot);
			*cand = tmp_cand;
			*opc = tmp_opcount;
		}
	}
	return (pot_tot);
}

int	cand_obv(t_stacks *stacks, t_opcount *opc, t_intlist **cand, int tot)
{
	int			steps;
	t_intlist	*tmp_cand;
	t_opcount	tmp_opcount;
	int			pot_tot;

	if (tot <= stacks->len_b)
		steps = tot;
	else
		steps = stacks->len_b;
	tmp_cand = stacks->b;
	while (steps-- > 0)
	{
		tmp_cand = tmp_cand->next;
		tmp_opcount = check_cand_opcount(stacks, tmp_cand);
		pot_tot = count_total(tmp_opcount);
		if (pot_tot < tot)
		{
			steps -= (tot - pot_tot);
			*cand = tmp_cand;
			*opc = tmp_opcount;
		}
	}
	return (pot_tot);
}

t_intlist *find_cand(t_stacks *stacks, t_opcount *pot_opcount, int cur_tot)
{
	t_intlist	*pot_candidate;
	int			pot_tot;
	t_opcount	new_opcount;
	
	pot_candidate = NULL;
	new_opcount = init_opcount();
	pot_tot = cand_obv(stacks, &new_opcount, &pot_candidate, cur_tot);
	if (pot_candidate)
		cur_tot = pot_tot;
	cand_rev(stacks, &new_opcount, &pot_candidate, cur_tot);
	if (pot_candidate)
		*pot_opcount = new_opcount;
	return (pot_candidate);
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
//	t_intlist	*lis_start;
//	int			lis_len;
//	t_intlist	*target;
//	int			rev_count;
//	int			i;

	//print_stack(stacks->a, stacks->len_a, 'a', 0);
//	lis_start = stacks->a;
//	lis_len = find_lis(stacks, &lis_start, stacks->a, stacks->len_a);
//	while (stacks->a != lis_start)
//		do_op(stacks, op_push, stack_b, 1);
//	ft_printf("lis_start: %d\n", lis_start->element);
//	ft_printf("lis_len: %d\n", lis_len);
//	target = stacks->a;
//	i = lis_len;
//	while (i--)
//		target = target->next;
//	rev_count = count_rev_rots(stacks->a, target);
//	if (rev_count * 2 < stacks->len_a)
//		do_op(stacks, op_rrot, stack_a, rev_count);
//	else
//		do_op(stacks, op_rot, stack_a, lis_len);
//	while (stacks->a != lis_start)
//		do_op(stacks, op_push, stack_b, 1);
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
		opcount = check_cand_opcount(stacks, candidate);
		pot_opcount = init_opcount();
		pot_candidate = find_cand(stacks, &pot_opcount, count_total(opcount));
		if (pot_candidate)
			opcount = pot_opcount;
		execute_operations(stacks, opcount);
		if (stacks->a->element < stacks->head_a->element)
			stacks->head_a = stacks->a;
		if (stacks->a->element > stacks->tail_a->element)
			stacks->tail_a = stacks->a;
	}
	if (stacks->a != stacks->head_a)
		put_lowest_on_top(stacks);
}
