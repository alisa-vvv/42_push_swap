#include "../push_swap.h"

int	choose_pivot(t_stacks *stacks, e_op_stack op_stack, t_intlist *last_el)
{
	t_intlist	*cur_node;
	int			min;
	int			max;

	if (op_stack == stack_a)
		cur_node = stacks->a;
	if (op_stack == stack_b)
		cur_node = stacks->b;
	max = cur_node->element;
	cur_node = cur_node->next;
	while (cur_node != last_el->next)
	{
		if (cur_node->element > max)
			max = cur_node->element;
		cur_node = cur_node->next;
	}
	min = cur_node->element;
	cur_node = cur_node->next;
	while (cur_node != last_el->next)
	{
		if (cur_node->element < min)
			min = cur_node->element;
		cur_node = cur_node->next;
	}
	return (min + (max - min) / 2);
}

t_intlist	*div_a(t_stacks *stacks, t_intlist *first_sorted, t_intlist *last)
{
	const int	pivot = choose_pivot(stacks, stack_a, last);
	int			count;

	ft_printf("median a: %d\n", pivot);
	count = stacks->len_a;
	while (stacks->a != first_sorted && count--)
	{
		ft_printf("count: %d\n", count);
		if (stacks->a->element <= pivot)
			do_op(stacks, op_push, stack_b, 1);
		do_op(stacks, op_rot, stack_a, 1);
	}
	if (stacks->len_a <= 3)
	{
		sort_small_stack(stacks, stack_a, stacks->len_a);
		first_sorted = stacks->a;
	}
	if (first_sorted)
		ft_printf("first_sorted = %d\n", first_sorted->element);
	return (first_sorted);
}

t_intlist	*div_b(t_stacks *stacks, t_intlist *first_sorted, t_intlist *last)
{
	const int	pivot = choose_pivot(stacks, stack_b, last);
	int			count;

	ft_printf("median b: %d\n", pivot);
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

// 1) Write the algorithm for sorting tree values at the top of a stack that's bigger than 3 values;
// 2) Keep track of the start separately from current rotation of array (do I need that?)
// 3) Eh? 

void	quicksort(t_stacks *stacks, t_intlist *sorted_a, t_intlist *sorted_b)
{
	t_intlist	*last_el_a;
	t_intlist	*last_el_b;
	int			test = 3;

	ft_printf("START\n");
	while (test--)
	{
		while (stacks->len_a > 3)
		{
			if (!sorted_a)
				last_el_a = stacks->a->prev;
			else
				last_el_a = sorted_a->prev;
			ft_printf("last_el_a = %d\n", last_el_a->element);
			ft_printf("first_el_a = %d\n", stacks->a->element);
			sorted_a = div_a(stacks, sorted_a, last_el_a);
			print_stack(stacks->a, stacks->len_a, 'a', 1);
		}
		while (stacks->len_b > 3)
		{
			if (!sorted_b && stacks->b)
				last_el_b = stacks->b->prev;
			else
				last_el_b = sorted_b->prev;
			sorted_b = div_b(stacks, sorted_b, last_el_a);
		}
	}
}
//	print_stack(stacks->b, stacks->len_b, 'b', 1);
//	print_stack(stacks->a, stacks->len_a, 'a', 1);

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

