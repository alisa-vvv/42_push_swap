#include "push_swap.h"

e_rot_dir   determine_rot_dir(t_intlist *target, t_intlist *top)
{
    t_intlist   *cur_node;
    int     	rot_count;

    cur_node = top;
    rot_count = 0;
    while (cur_node != target)
    {
        cur_node = cur_node->next;
        rot_count++;
    }
	cur_node = top;
	while (cur_node!= target)
	{
		cur_node = cur_node->prev;
		rot_count--;
	}
	if (rot_count > 0)
    	return (reverse);
	else
		return (obverse);
}

void    rot_to(t_intlist *target, t_stacks *stacks, e_op_stack stack)
{
    t_intlist   *cur_node;
    e_rot_dir   dir;

	if (stack == stack_a)
		cur_node = stacks->a;
	if (stack == stack_b)
		cur_node = stacks->b;
	if (cur_node == target)
		return ;
    dir = determine_rot_dir(target, cur_node);
    if (dir == obverse)
    {
        while (cur_node != target)
		{
			cur_node = cur_node->next;
            do_op(stacks, op_rot, stack, 1);
		}
    }
    else if (dir == reverse)
    {
        while (cur_node != target)
		{
			cur_node = cur_node->prev;
            do_op(stacks, op_rrot, stack, 1);
		}
    }
}
 
t_intlist	*find_target_a(t_intlist *top_unsorted, int pivot)
{
	t_intlist *cur_node;

	cur_node = top_unsorted;
	while (cur_node->element <= pivot)
		cur_node = cur_node->next;
	return (cur_node);
}

e_rot_dir	shortest_path_a(t_intlist *orig_pos, int piv, int count)
{
	t_intlist	*cur_node;
	int			rot_count;
	int			el_count;

	el_count = count;
	cur_node = orig_pos;
	rot_count = 0;
	while (count)
	{
		if (cur_node->sorted == false && cur_node->element < piv)
		{
			count--;
			rot_count--;
		}
		cur_node = cur_node->next;
		rot_count++;
	}
	cur_node = orig_pos;
	while (el_count)
	{
		if (cur_node->sorted == false && cur_node->element < piv)
		{
			el_count--;
			rot_count--;
		}
		cur_node = cur_node->prev;
		rot_count--;
	}
	if (rot_count > 0)
		return (reverse);
	else
		return (obverse);
}

t_intlist	*find_target_b(t_intlist *top_unsorted, int pivot)
{
	t_intlist *cur_node;

	cur_node = top_unsorted;
	while (cur_node->element >= pivot)
		cur_node = cur_node->next;
	return (cur_node);
}

e_rot_dir	shortest_path_b(t_intlist *orig_pos, int piv, int count)
{
	t_intlist	*cur_node;
	int			rot_count;
	int			el_count;

	el_count = count;
	cur_node = orig_pos;
	rot_count = 0;
	while (count)
	{
		if (cur_node->sorted == false && cur_node->element > piv)
		{
			count--;
			rot_count--;
		}
		cur_node = cur_node->next;
		rot_count++;
	}
	cur_node = orig_pos;
	while (el_count)
	{
		if (cur_node->sorted == false && cur_node->element > piv)
		{
			el_count--;
			rot_count--;
		}
		cur_node = cur_node->prev;
		rot_count--;
	}
	if (rot_count > 0)
		return (reverse);
	else
		return (obverse);
}

// make a version for B to sort them in the opposite order
void	sort_last_three(t_stacks *stacks, e_op_stack stack, t_intlist *node)
{
	const int val1 = node->element;
	const int val2 = node->next->element;
	const int val3 = node->next->next->element;

	if (val1 < val2 && val2 > val3)
	{
		do_op(stacks, op_rot, stack, 1);
		do_op(stacks, op_swap, stack, 1);
		do_op(stacks, op_rrot, stack, 1);
		if (val3 < val1)
			do_op(stacks, op_swap, stack, 1);
	}
	if ((val1 > val2 && val2 < val3 && val3 < val1)
		|| (val1 > val2 && val2 > val3))
	{
		do_op(stacks, op_swap, stack, 1);
		do_op(stacks, op_rot, stack, 1);
		do_op(stacks, op_swap, stack, 1);
		do_op(stacks, op_rrot, stack, 1);
		if (val1 > val2 && val2 > val3)
			do_op(stacks, op_swap, stack, 1);
	}
	if (val1 > val2 && val2 < val3 && val3 > val1)
		do_op(stacks, op_swap, stack, 1);
}

void	update_sorted(t_stacks *stacks, e_op_stack stack, int count)
{
	t_intlist	*cur_node;

	if (stack == stack_a)
	{
		cur_node = stacks->a;
		stacks->sorted_top_a = stacks->a;
		stacks->sorted_bot_a = stacks->a->prev;
	}
	if (stack == stack_b)
	{
		cur_node = stacks->b;
		stacks->sorted_top_b = stacks->b;
		stacks->sorted_bot_b = stacks->b->prev;
	}
	while (count--)
	{
		cur_node->sorted = true;
		cur_node = cur_node->next;
	}
}

void	sort_last_div(t_stacks *stacks, e_op_stack stack, int count)
{
	t_intlist	*cur_node;
		
	if (!count)
		return ;
	if (stack == stack_a)
	{
		if (stacks->sorted_bot_a)
			rot_to(stacks->sorted_bot_a->next, stacks, stack);
		cur_node = stacks->a;
	}
	if (stack == stack_b)
	{
		if (stacks->sorted_bot_b)
			rot_to(stacks->sorted_bot_b->next, stacks, stack);
		cur_node = stacks->b;
	}
	if (count == 2)
	{
		if (cur_node->element > cur_node->next->element)
			do_op(stacks, op_swap, stack, 1);
	}
	else if (count == 3)
		sort_last_three(stacks, stack, cur_node);
	update_sorted(stacks, stack, count);
}

void	div_a(t_stacks *stacks, int *sorted_count, int pivot, e_rot_dir dir)
{
	int			count;
	e_op_name	op;

	if (dir == obverse)
		op = op_rot;
	else
		op = op_rrot;
	count = (stacks->len_a - *sorted_count) / 2 - 1;
	while (count)
	{
		if (stacks->a->element < pivot)
		{
			do_op(stacks, op_push, stack_b, 1);
			count--;
		}
		else
			do_op(stacks, op, stack_a, 1);
	}
}

void	div_b(t_stacks *stacks, int *sorted_count, int pivot, e_rot_dir dir)
{
	int			count;
	e_op_name	op;

	if (dir == obverse)
		op = op_rot;
	else
		op = op_rrot;
	count = (stacks->len_b - *sorted_count) / 2;
	while (count)
	{
		if (stacks->b->element > pivot)
		{
			do_op(stacks, op_push, stack_a, 1);
			count--;
		}
		else
			do_op(stacks, op, stack_b, 1);
	}
}

void	quicksort(t_stacks *stacks)
{
	int			sorted_a;
	int			sorted_b;
	int			pivot; // this should ne put inside a and b things
	int			is_odd;
	t_med_arrs	*med_arrs;
	e_rot_dir	dir;

	sorted_a = 0;
	sorted_b = 0;
	is_odd = (stacks->len_a - sorted_a) % 2 != 0;
	med_arrs = alloc_med_arrs(stacks->a, stacks->len_a);
	while (sorted_a != stacks->len_a || sorted_b != stacks->len_b)
	{
		while (stacks->len_a - sorted_a > 3)
		{
			//	rot_to(stacks->sorted_bot_a->next, stacks, stack_a);
			is_odd = (stacks->len_a - sorted_a) % 2 != 0;
			if (stacks->sorted_bot_a)
			{
				put_part_on_arr(med_arrs, stacks->sorted_bot_a->next, stacks->len_a - sorted_a);
				pivot = find_median(med_arrs, stacks->len_a - sorted_a, is_odd + ((stacks->len_a - sorted_a) / 2));
			}
			else
			{
				put_part_on_arr(med_arrs, stacks->a, stacks->len_a - sorted_a);
				pivot = find_median(med_arrs, stacks->len_a - sorted_a, is_odd + ((stacks->len_a - sorted_a) / 2));
			}
			dir = shortest_path_a(stacks->a, pivot, (stacks->len_a - sorted_a) / 2 - 1);
			div_a(stacks, &sorted_a, pivot, dir);
		}
		sort_last_div(stacks, stack_a, stacks->len_a - sorted_a);
		sorted_a += stacks->len_a - sorted_a;
		// comment for readability, b starts after this
		while (stacks->len_b - sorted_b > 3)
		{
			//rot_to(stacks->sorted_bot_b->next, stacks, stack_b);
			if (stacks->sorted_bot_b)
			{
				put_part_on_arr(med_arrs, stacks->sorted_bot_b->next, stacks->len_b - sorted_b);
				pivot = find_median(med_arrs, stacks->len_b - sorted_b, is_odd + ((stacks->len_b - sorted_b) / 2));
			}
			else
			{
				put_part_on_arr(med_arrs, stacks->b, stacks->len_b - sorted_b);
				pivot = find_median(med_arrs, stacks->len_b - sorted_b, is_odd + ((stacks->len_b - sorted_b) / 2));
			}
			dir = shortest_path_b(stacks->b, pivot, (stacks->len_b - sorted_b) / 2 - 1);
			div_b(stacks, &sorted_b, pivot, dir);
		}
		sort_last_div(stacks, stack_b, stacks->len_b - sorted_b);
		sorted_b += stacks->len_b - sorted_b;
	}
//	print_stack(stacks->a, stacks->len_a, 'a', 0);
//	print_stack(stacks->b, stacks->len_b, 'b', 0);
	free_med_arrs(med_arrs);
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

