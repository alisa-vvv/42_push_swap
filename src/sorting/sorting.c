#include "push_swap.h"

//	Start with elmeent 1 in b
//	STEP1:
//	1) Count rotations to chosen element in b
//	2) If it's bigger than current total_count, stop
//	2) Find the place in a where it belongs to
//	3) Count rotations needed to perform in a to get to the element after place
//	4) check if these rotations can be performed at the same time
//	5) reutrn the total number of rotations
//	6) compare to current total steps, if bigger, stop;
//	STEP2:
//	1) if number of total steps is lower than previous, add the push action
//	2) if it's still lower, you found current candidate
//	3) save the candidate and number of steps
//	4) keep going in both of the rotation directions until all possible candidatesare checked

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

//to be reweitten
t_intlist *find_cand_place(t_stacks *stacks, int cand_val, int len)
{
	t_intlist	*cur_node;

	if (cand_val < stacks->head_a->element || cand_val > stacks->tail_a->element)
	{
		ft_printf("el is top or bot\n");
		ft_printf("and the value is: %d\n", stacks->head_a->element);
		return (stacks->head_a);
	}
	cur_node = stacks->a;
	while (len--)
	{
		if (cand_val > cur_node->prev->element && cand_val < cur_node->element)
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

int	check_count(int total_count, t_opcount cur_opcount)
{
	if (total_count && total_count < cur_opcount.rb_count
		&& total_count < cur_opcount.rrb_count
		&& total_count < cur_opcount.ra_count
		&& total_count < cur_opcount.rra_count)
		return (total_count + 1);
	return (total_count);
}

//to be reweitten
t_intlist *find_cand(t_stacks *stacks, t_opcount *cur_opcount, int tot_c)
{
	int			len;
	t_intlist	*candidate;

	len = stacks->len_b;
	candidate = stacks->b;
	while (len--)
	{
		candidate = candidate->next;
		count_b(stacks->b, cur_opcount, candidate);
		count_a(stacks, cur_opcount, candidate);
		if (check_count(tot_c, *cur_opcount) > tot_c)
			break ;
	}
	candidate = stacks->b;
	while (len--)
	{
		candidate = candidate->prev;
		count_b(stacks->b, cur_opcount, candidate);
		count_a(stacks, cur_opcount, candidate);
		if (check_count(tot_c, *cur_opcount) > tot_c)
			break ;
	}
	return (candidate);
}

//to be reweitten
// pass pointers to current candidat erelated stuff
// here, crate pot_candidate related stuff
// run through stack b and update the current candidate until checked all within range/found candidate
// profit
//t_intlist	*find_cheapest(t_stacks *stacks, t_opcount *opcount)
//{
//	int			total_count;
//	t_intlist	*candidate;
//	t_opcount	cur_opcount;
//
//	total_count = 0;
//	*opcount = cur_opcount;
//	return (candidate);
//}

void	turk(t_stacks *stacks)
{
//	int			total_count;
	t_opcount	opcount;
//	t_opcount	pot_opcount;
	t_intlist	*candidate;
//	t_intlist	*pot_candidate;

	do_op(stacks, op_push, stack_b, stacks->len_a - 1);
	stacks->head_a = stacks->a;
	stacks->tail_a = stacks->a;

	candidate = stacks->b;
	opcount = init_opcount();
	count_a(stacks, &opcount, candidate);
	count_b(stacks->b, &opcount, candidate);
	ft_printf("checking if can find place: %d\n", find_cand_place(stacks, candidate->element, stacks->len_b)->element);
//	total_count = count_total(opcount);
//	pot_opcount = init_opcount();
//	pot_candidate = find_cheapest(stacks, &pot_opcount);
//	if (total_count < count_total(pot_opcount))
//		ft_printf("cur is cheaper\n");
//	else
//		ft_printf("pot is cheaper\n");
//	ft_printf("cur_candidate value: %d\n", candidate->element);
//	ft_printf("pot_candidate value: %d\n", pot_candidate->element);
//	int	test = 2;
//	//while (stacks->len_b)
//	while (test--)
//	{
//	//	print_stack(stacks->a, stacks->len_a, 'a', 1);
//	//	ft_printf("ra_count: %d\n", opcount.ra_count);
//	//	ft_printf("rra_count: %d\n", opcount.rra_count);
//	//	print_stack(stacks->b, stacks->len_b, 'b', 1);
//	//	ft_printf("candidate value: %d\n", candidate->element);
//	//	ft_printf("rb_count: %d\n", opcount.rb_count);
//	//	ft_printf("rrb_count: %d\n", opcount.rrb_count);
//	//	ft_printf("pa_count: %d\n", opcount.pa_count);
//	//	do_op(stacks, op_push, stack_a, 1);
//	//	if (candidate > stacks->tail_a)
//	//		stacks->tail_a = candidate;
//	//	if (candidate < stacks->head_a)
//	//		stacks->head_a = candidate;
//	}
}
