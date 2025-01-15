#include "push_swap.h"

t_intlist	*choose_pivot(t_stacks *stacks, e_op_stack op_stack)
{
	t_intlist	*cur_node;

	if (op_stack == stack_a)
		cur_node = stacks->a;
	else
		cur_node = stacks->b;
//	int	values[3];
//	int	comp;
//
//	el1 = cur_node->element;
//	el2 = cur_node->prev->element;
//	len = len / 2;
//	while (len--)
//		cur_node = cur_node->next;
//	el3 = cur_node->element;
//	while (el3 < comp)
//	{
//		comp = el1;
//	}
	return (cur_node);
}

//void	qs_a_swap(t_intlist *low, t_intlist *high, t_stacks *stacks, t_intlist *pivot)
//{
//	e_rot_dir	rot_dir_low;
//	e_rot_dir	rot_dir_high;
//	t_intlist	*cur_node;
//	t_intlist	*low_prev;
//
//	rot_dir_high = determine_rot_dir(high_val);
//	rot_dir_low = determine_rot_dir(low_val);
//	pb(stacks);
//	if (rot_dir_low == CLOCKWISE)
//	{
//		while (stacks->a != low_val)
//			rra(stacks);
//	}
//	else
//	{
//		while (stacks->a != low_val)
//			ra(stacks);
//	}
//	// this can be optimized by eliming rotation if there's onnly one element
//	if (stacks->b->element = pivot)
//		rb(stacks);
//}
//
//e_rot_dir	determine_rot_dir (t_intlist *target, t_intlist *top, int len)
//{
//	t_intlist	*cur_node;
//	int		rot_count;
//	
//	cur_node = top;
//	rot_count = 0;
//	while (cur_node != target)
//	{
//		if (rot_count * 2 > len)
//			return (CR_CLOCKWISE);
//		cur_node = cur_node->next;
//		rot_count++;
//	}
//	return (CLOCKWISE);
//}
//
//t_intlist	*qs_comp(t_intlist *start, t_intlist *end, e_rot_dir dir, int pivot)
//{
//	t_intlist	*cur_node;
//
//	cur_node = start;
//	if (dir == CLOCKWISE)
//	{
//		while (cur_node != end)
//		{
//			if (cur_node->element < pivot)
//				return (cur_node);
//			cur_node = cur_node->next;
//		}
//	}
//	if (dir == CR_CLOCKWISE)
//	{
//		while (cur_node != end)
//		{
//			if (cur_node->element > pivot)
//				return (cur_node);
//			cur_node = cur_node->prev;
//		}
//	}
//	return (cur_node);
//}

void	sort_three(char a_b, t_intlist *sorted_stack, t_stacks *stacks) {
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

int		parse_stack(t_stacks *stacks, e_op_name op, e_op_stack op_stack)
{
	const *t_intlist	pivot = choose_pivot(stacks, e_op_stack);

}

void	quicksort(t_stacks *stacks)
{
	t_intlist	*pivot;
	t_intlist	*cur_node;
	int			cur_len;

	cur_len = stacks->len_a;
	pb(stacks); // this should go to list first
	ft_printf("pivot: %d\n", pivot->element);
	while (cur_node->element > pivot->element)
		
}
