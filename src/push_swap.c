#include "push_swap.h"

static void	do_n_times(t_stacks *stacks, void (*f)(t_stacks *stacks), int n)
{
	while(n--)
		f(stacks);
}

void	do_rot(t_stacks *stacks, e_op_name op, e_op_stack stack, int n)
{
	if (op == op_rot)
	{
		if (stack == stack_a)
			do_n_times(stacks, ra, n);
		else if (stack == stack_b)
			do_n_times(stacks, rb, n);
		else
			do_n_times(stacks, rr, n);
	}
	if (op == op_rrot)
	{
		if (stack == stack_a)
			do_n_times(stacks, rra, n);
		else if (stack == stack_b)
			do_n_times(stacks, rrb, n);
		else
			do_n_times(stacks, rrr, n);
	}
}

void	do_op(t_stacks *stacks, e_op_name op, e_op_stack stack, int n)
{
	if (op == op_swap)
	{
		if (stack == stack_a)
			do_n_times(stacks, sa, n);
		else if (stack == stack_b)
			do_n_times(stacks, sb, n);
		else
			do_n_times(stacks, ss, n);
	}
	else if (op == op_push)
	{
		if (stack == stack_a)
			do_n_times(stacks, pa, n);
		else if (stack == stack_b)
			do_n_times(stacks, pb, n);
	}
	else
		do_rot(stacks, op, stack, n);
}

int	is_sorted(t_intlist *node, int len)
{
	len -= 1;
	while (len--)
	{
		if (node->next->element < node->element)
			return (0);
		node = node->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 1 || argc == 2)	
		exit (0);
	stacks = allocate_stacks(argc - 1);
	if (!stacks)
		free_exit(stacks, 1);
	fill_stack(stacks, argc - 1, &argv[1]);
	if (is_sorted(stacks->a, stacks->len_a))
		free_exit(stacks, 0);
	if (argc <= 4)
		sort_small_stack(stacks, stack_a, stacks->len_a);
	else
		turk(stacks);
//	print_stack(stacks->a, stacks->len_a, 'a', 0);
//	print_stack(stacks->b, stacks->len_b, 'b', 0);
	free_exit(stacks, 0);
	return (0);
}
