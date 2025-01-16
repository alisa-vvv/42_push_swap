#include "../push_swap.h"

int	choose_pivot(t_stacks *stacks, e_op_stack op_stack, t_intlist *last_el)
{
	t_intlist	*cur_node;
	t_intlist	*DELETE_THIS = last_el;
//	int			val1;
//	int			val2;
//	int			val3;
//	int			len;
//
	if (op_stack == stack_a)
	{
		cur_node = stacks->a;
//		val1 = stacks->a->element;
//		val2 = last_el->element;
	}
	else
	{
		cur_node = stacks->b;
//		val1 = stacks->b->element;
//		val2 = last_el->element;
	}
	DELETE_THIS = NULL;
//	if (last_el->next == cur_node)
//	len = 0;
//	while (cur_node != last_el)
//	{
//		cur_node = cur_node->next;
//		len++;
//	}
//	len /= 2;
//	while (len--)
//		cur_node = cur_node->next;
//	val3 = cur_node->element;
//	if ((val1 < val2 && val1 > val3) || (val1 > val2 && val1 < val3))
//		return (val1);
//	if ((val2 < val1 && val2 > val3) || (val2 > val1 && val2 < val3))
//		return (val2);
//	return (val3);
	return (cur_node->element);
}

t_intlist	*div_a(t_stacks *stacks, t_intlist *first_sorted, t_intlist *last)
{
	const int	pivot = choose_pivot(stacks, stack_a, last);
	int			count;

	count = stacks->len_a;
	while (stacks->a != first_sorted && count--)
	{
		if (stacks->a->element <= pivot)
			do_op(stacks, op_push, stack_b, 1);
		do_op(stacks, op_rot, stack_a, 1);
	}
	if (stacks->len_a <= 3)
	{
		sort_small_stack(stacks, stack_a, stacks->len_a);
		first_sorted = stacks->a;
	}
	return (first_sorted);
}

t_intlist	*div_b(t_stacks *stacks, t_intlist *first_sorted, t_intlist *last)
{
	const int	pivot = choose_pivot(stacks, stack_b, last);
	int			count;

	count = stacks->len_b;
	while (stacks->b != first_sorted && count--)
	{
		if (stacks->b->element >= pivot)
			do_op(stacks, op_push, stack_a, 1);
		do_op(stacks, op_rot, stack_b, 1);
	}
	if (stacks->len_b <= 3)
	{
		sort_small_stack(stacks, stack_b, stacks->len_b);
		first_sorted = stacks->b;
	}
	return (first_sorted);
}

void	quicksort(t_stacks *stacks, t_intlist *sorted_a, t_intlist *sorted_b)
{
	t_intlist	*last_el_a;
	t_intlist	*last_el_b;
	int			test_val = 1;

	while (test_val--)
	{
		if (!sorted_a)
			last_el_a = stacks->a->prev;
		else
		{
			last_el_a = sorted_a->prev;
		}
		while (stacks->len_a > 3)
			sorted_a = div_a(stacks, sorted_a, last_el_a);
		if (!sorted_b && stacks->b)
			last_el_b = stacks->b->prev;
		else
			last_el_b = sorted_b->prev;
		while (stacks->len_b > 3)
			sorted_b = div_b(stacks, sorted_b, last_el_a);
	}
	ft_printf("sorted_a = %d\n", sorted_a->element);
	ft_printf("last_el_a = %d\n", last_el_a->element);
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

