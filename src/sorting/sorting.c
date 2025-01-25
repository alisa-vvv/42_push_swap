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

t_intlist *find_cand_place(t_stacks *stacks, int cand_val, int len)
{
	t_intlist	*cur_node;

	if (cand_val < stacks->head_a->element || cand_val > stacks->tail_a->element)
		return (stacks->head_a);
	cur_node = stacks->a;
	while (len--)
	{
		if (cand_val > cur_node->element && cand_val < cur_node->next->element)
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

t_intlist	*find_cheapest(t_stacks *stacks, t_opcount *opcount)
{
	int			total_count;
	t_intlist	*candidate;
	t_intlist	*cand_place;
	int			len;
	t_opcount	cur_opcount;

	total_count = 0;
	candidate = stacks->b->prev;
	len = stacks->len_b;
	while (len--)
	{
		candidate = candidate->next;
		cur_opcount.rb_count = count_obv_rots(stacks->b, candidate);
		if (total_count && total_count < cur_opcount.rb_count)
			continue ;
		cand_place = find_cand_place(stacks, candidate->element, stacks->len_a);
		cur_opcount.ra_count = count_obv_rots(stacks->a, cand_place);
		cur_opcount.rra_count = count_rev_rots(stacks->a, cand_place);
		break ;
	}
	cur_opcount.pa_count = 1;
	*opcount = cur_opcount;
	return (candidate);
}

void	turk(t_stacks *stacks)
{
	t_opcount	opcount;
	t_intlist	*candidate;

	do_op(stacks, op_push, stack_b, stacks->len_a - 1);
	stacks->head_a = stacks->a;
	stacks->tail_a = stacks->a;
	candidate = stacks->b;

	int	test = 2;
	//while (stacks->len_b)
	while (test--)
	{
		candidate = find_cheapest(stacks, &opcount);
		print_stack(stacks->a, stacks->len_a, 'a', 1);
		print_stack(stacks->b, stacks->len_b, 'b', 1);
		ft_printf("candidate value: %d\n", candidate->element);
		ft_printf("rb_count: %d\n", opcount.rb_count);
		ft_printf("ra_count: %d\n", opcount.ra_count);
		ft_printf("rra_count: %d\n", opcount.rra_count);
		ft_printf("pa_count: %d\n", opcount.pa_count);
		do_op(stacks, op_push, stack_a, 1);
		if (candidate > stacks->tail_a)
			stacks->tail_a = candidate;
		if (candidate < stacks->head_a)
			stacks->head_a = candidate;
	}
}
