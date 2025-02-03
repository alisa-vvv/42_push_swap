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

// need a funciton that will check the smallest possible combination out of 4.
// it will count rotations that can be saved by doing rr or rrr insead of separate
// rotations.
// the  4 possible combinations are:
// 1) the smallest amount of action is rr (combine ra and rb, get ocunt of rr instead)
// 2) the smallest amount is rrr (combine rra and rrb, get count of rrr instead)
// 3-4) the smallest amount is doing actions without combining:
// 		3) some ra's and some rrb's
// 		4) some rra's and some rb's
// get that by counting:
// 1) if there's both racount and rbcount, reduce both,increment rrcount;
// 2) if there's both rracount and rrbcount, decrement both, incrememnt rrrcount;
// 3) count ra's + rrb's;
// 4) count rra's + rb's;
// compare the 4 values, choose the smallest total.
// can be done by having 4 t_opcounts and a function for counting per combnation

t_opcount	count_rr(t_opcount opcount)
{
	t_opcount	rr_opcount;

	rr_opcount = init_opcount();
	if (opcount.ra_count && opcount.rb_count)
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
	if (opcount.rra_count && opcount.rrb_count)
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
t_intlist *find_cand(t_stacks *stacks, t_opcount *pot_opcount, int cur_tot)
{
	int			len;
	t_intlist	*pot_candidate;

	len = stacks->len_b;
	pot_candidate = stacks->b;
	//instead of len, this should use a clone of cur_total. this way, we don't have to use check_count every time, we will naturally know when to stop looking
	while (len--)
	{
		//inside the loops, if candidate is found, count all combinations, check if new total is bigger, move on if no, else, save it as pot_opcount. pot_opcount should be nill by default so we can check if one that's smaller than cur is found it all (or have a separate value to track that)
		pot_candidate = pot_candidate->next;
		count_b(stacks->b, pot_opcount, pot_candidate);
		count_a(stacks, pot_opcount, pot_candidate);
		if (check_count(cur_tot, *pot_opcount) > cur_tot)
			break ;
	}
	pot_candidate = stacks->b;
	while (len--)
	{
		pot_candidate = pot_candidate->prev;
		count_b(stacks->b, pot_opcount, pot_candidate);
		count_a(stacks, pot_opcount, pot_candidate);
		if (check_count(cur_tot, *pot_opcount) > cur_tot)
			break ;
	}
	return (pot_candidate);
}

//to be reweitten
// pass pointers to current candidat erelated stuff
// here, crate pot_candidate related stuff
// run through stack b and update the current candidate until checked all within range/found candidate
// this is done by running find_cand, then running a separate compare function I think once a cand is found
// profit
t_intlist	*find_cheapest(t_stacks *stacks, int *cur_total) 
{
	t_intlist	*pot_candidate;
	t_opcount	pot_opcount;

	pot_candidate = find_cand(stacks, &pot_opcount, cur_total);
	return (pot_candidate);
}

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
