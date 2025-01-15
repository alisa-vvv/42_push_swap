#include "push_swap.h"

t_intlist	*choose_pivot(t_intlist *cur_node, int len)
{
//	int	values[3];
//	int	comp;
//
//	el1 = cur_node->element;
//	el2 = cur_node->prev->element;
//	len = len / 2;
//	while (len--)
//		cur_node = cur_node->next;
	len = 0; // REMOVE THIS THIS IS FOR COMPILER TO NOT CRY
	return (cur_node);
//	el3 = cur_node->element;
//	while (el3 < comp)
//	{
//		comp = el1;
//	}
	return (cur_node);
}

e_rot_dir	determine_rot_dir (t_intlist *target, t_intlist *top, int len)
{
	t_intlist	*cur_node;
	int		rot_count;
	
	cur_node = top;
	rot_count = 0;
	while (cur_node != target)
	{
		if (rot_count * 2 > len)
			return (CR_CLOCKWISE);
		cur_node = cur_node->next;
		rot_count++;
	}
	return (CLOCKWISE);
		
}
t_intlist	*qs_comp(t_intlist *start, t_intlist *end, e_rot_dir dir, int pivot)
{
	t_intlist	*cur_node;

	cur_node = start;
	if (dir == CLOCKWISE)
	{
		while (cur_node != end)
		{
			if (cur_node->element < pivot)
				return (cur_node);
			cur_node = cur_node->next;
		}
	}
	if (dir == CR_CLOCKWISE)
	{
		while (cur_node != end)
		{
			if (cur_node->element >= pivot)
				return (cur_node);
			cur_node = cur_node->prev;
		}
	}
	return (cur_node);
}

void	sort_three(char a_b, t_intlist *sorted_stack, t_stacks *stacks)
{
	const int el1 = sorted_stack->element;
	const int el2 = sorted_stack->next->element;
	const int el3 = sorted_stack->prev->element;
	
	if (el1 < el2 && el2 < el3)
		return ;
	if (el1 < el2 && el2 > el3)
	{
		if (a_b == 'a')
			rra(stacks);
		else
			rrb(stacks);
	}
	if ((el1 > el2 && el2 > el3) || (el1 > el2 && el2 < el3 && el3 < el1))
	{
		if (a_b == 'a')
			ra(stacks);
		else
			rb(stacks);
	}
	if ((el1 < el2 && el2 > el3 && el3 > el1) || (el1 > el2 && el2 > el3)
			|| (el1 > el2 && el2 < el3 && el3 > el1))
	{
		if (a_b == 'a')
			sa(stacks);
		else
			sb(stacks);
	}
}

// This should probably return the oplist.
void	quicksort(t_stacks *stacks, t_oplist *oplist, t_opcount *opcount)
{
	t_intlist	*pivot;
	t_intlist	*low_val;
	t_intlist	*high_val;
	int			cur_len;

	// REMOVE THIS, THESE VALUES WILL BE REAL LATER
	oplist = NULL;
	opcount = NULL;

	pivot = choose_pivot(stacks->a, stacks->len_a);
	cur_len = stacks->len_a;
	pb(stacks); // this should go to list first
	ft_printf("pivot: %d\n", pivot->element);
	low_val = qs_comp(stacks->a, stacks->a->prev, CLOCKWISE, pivot->element);
	high_val = qs_comp(stacks->a->prev, stacks->a, CR_CLOCKWISE, pivot->element);

	ft_printf("this should be less then pivot: %d\n", low_val->element);
	ft_printf("this should be higher than puvot: %d\n", high_val->element);
}
