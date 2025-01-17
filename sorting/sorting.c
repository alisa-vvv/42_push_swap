#include "../push_swap.h"

//int	count_unsorted(t_intlist *cur_node, int total_len)
//{
//	int	count;
//
//	count = 0;
//	while (total_len--)
//	{
//		if (cur_node->sorted == no)
//			count++;
//		cur_node = cur_node->next;
//	}
//	return (count);
//}

int	choose_pivot(t_intlist *top_node, int len, int mid_pos, int *median_arr)
{
	t_intlist	*cur_node;
	int			first_small;
	int 		last_big;
	int			chosen_el;
	int			el_count;

	cur_node = top_node;
	el_count = len;
	chosen_el = cur_node->element;
	cur_node = cur_node->next;
	first_small = len;
	last_big = -1;
	while (el_count-- && cur_node->sorted == no)
	{
		if (cur_node->element < chosen_el)
			median_arr[--first_small] = cur_node->element;
		else
			median_arr[++last_big] = cur_node->element;
		cur_node = cur_node->next;
	}
	if (len - first_small + 1 != mid_pos)
		return (choose_pivot(top_node->next, len, mid_pos, median_arr));
	return (chosen_el);
}

void	div_a(t_stacks *stacks, e_rot_dir rot_dir, int *sorted_count, int pivot)
{
	int			count;

	count = stacks->len_a - *sorted_count;
	if (count == 1)
	{
		stacks->a->sorted = yes;
		(*sorted_count)++;
		return ;
	}
	if (rot_dir == obverse)
	{
		while (count--)
		{
			if (stacks->a->sorted == yes)
			{
				do_op(stacks, op_rrot, stack_a, 1);
				rot_dir = reverse;
				break ;
			}
			if (stacks->a->element <= pivot)
				do_op(stacks, op_push, stack_b, 1);
			do_op(stacks, op_rot, stack_a, 1);
		}
	}
	if (rot_dir == reverse && stacks->a->sorted == no)
	{
		while (count--)
		{
			if (stacks->a->element <= pivot)
				do_op(stacks, op_push, stack_b, 1);
			if (stacks->a->next->sorted == yes)
				break ;
			do_op(stacks, op_rrot, stack_a, 1);
		}
	}
//	if (stacks->len_a - (*sorted_count) <= 1)
//	{
//		stacks->a->sorted = yes;
//		(*sorted_count) += stacks->len_a;
//	}
}

void	div_b(t_stacks *stacks, e_rot_dir rot_dir, int *sorted_count, int pivot)
{
	int			count;

	count = stacks->len_b - *sorted_count;
	if (count == 1)
	{
		ft_printf("where seg\n");
		stacks->b->sorted = yes;
		(*sorted_count)++;
		return ;
	}
	if (rot_dir == obverse)
	{
		while (--count)
		{
			if (stacks->b->sorted == yes)
			{
				do_op(stacks, op_rrot, stack_b, 1);
				rot_dir = reverse;
				break ;
			}
			if (stacks->a->element >= pivot)
				do_op(stacks, op_push, stack_a, 1);
			do_op(stacks, op_rot, stack_b, 1);
		}
	}
	if (rot_dir == reverse && stacks->b->sorted == no)
	{
		while (--count)
		{
			if (stacks->b->element >= pivot)
				do_op(stacks, op_push, stack_a, 1);
			if (stacks->b->next->sorted == yes)
				break ;
			do_op(stacks, op_rrot, stack_b, 1);
		}
	}
//	if (stacks->len_b - (*sorted_count) == 1)
//	{
//		stacks->b->sorted = yes;
//		(*sorted_count) += stacks->len_b;
//	}
}


void	quicksort(t_stacks *stacks)
{
	int	sorted_a;
	int	sorted_b;
	int is_odd;
	int	pivot;
	int	*median_array;
	int	test = 1;

	ft_printf("START\n");
	sorted_a = 0;
	sorted_b = 0;
	//ft_printf("len: %d\n", stacks->len_a);
	median_array = (int *) malloc((stacks->len_a) * sizeof(int));
	while (test--)
	{
		is_odd = (stacks->len_a - sorted_a) % 2 != 0;
		while (sorted_a != stacks->len_a)
		{
			pivot = choose_pivot(stacks->a, stacks->len_a, is_odd + (stacks->len_a - sorted_a) / 2, median_array);
			div_a(stacks, obverse, &sorted_a, pivot);
		}
		// comment for readability, b starts after this
		is_odd = (stacks->len_b - sorted_b) %2 != 0;
		while (sorted_b != stacks->len_b)
		{
			pivot = choose_pivot(stacks->b, stacks->len_b, is_odd + (stacks->len_b - sorted_b) / 2, median_array);
			ft_printf("b pivot: %d\n", pivot);
			div_b(stacks, obverse, &sorted_b, pivot);
		}
		print_stack(stacks->b, stacks->len_b, 'b', 1);
		print_stack(stacks->a, stacks->len_a, 'a', 1);
	}
	free(median_array);
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

