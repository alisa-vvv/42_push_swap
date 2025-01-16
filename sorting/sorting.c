#include "push_swap.h"

int	choose_pivot(t_stacks *stacks, e_op_stack op_stack)
{
	t_intlist	*cur_node;
	const int	val1 = stacks->a->element;
	const int	val2 = stacks->a->prev->element;
	int			val3;
	int			len;

	if (op_stack == stack_a)
	{
		len = stacks->len_a / 2;
		cur_node = stacks->a;
	}
	else
	{
		len = stacks->len_b / 2;
		cur_node = stacks->b;
	}
	while (len--)
		cur_node = cur_node->next;
	val3 = cur_node->element;
	if ((val1 < val2 && val1 > val3) || (val1 > val2 && val1 < val3))
		return (val1);
	if ((val2 < val1 && val2 > val3) || (val2 > val1 && val2 < val3))
		return (val2);
	return (val3);
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

void		div_a(t_stacks *stacks, t_intlist *first_sorted)
{
	const int	pivot = choose_pivot(stacks, stack_a);
	int			count;

	count = stacks->len_a;
	while (stacks->a != first_sorted && count--)
	{
		if (stacks->a->element < pivot)
			do_op(stacks, op_push, stack_b, 1);
		do_op(stacks, op_rot, stack_a, 1);
	}
	if (stacks->len_a <= 3)
		ft_printf("this should call a function that sorts arrays of less than 3\n");
}

void	quicksort(t_stacks *stacks)
{
	t_intlist	*first_sorted_a;
	t_intlist	*first_sorted_b;

	first_sorted_a = NULL;
	first_sorted_b = NULL;
	while (stacks->len_a > 3)
		div_a(stacks, first_sorted_a);
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

