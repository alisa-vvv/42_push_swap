#include "push_swap.h"

void	do_n_times(t_stacks *stacks, void (*f)(t_stacks *stacks), int n)
{
	while(n--)
		f(stacks);
}

//void	do_op(t_stacks *stacks, e_ops op, e_op_stack stack, int n)
//{
//	if (op == swap)
//	{
//		if (stack == a)
//			do_n_times(stacks, sa, n);
//		else if (stack == b)
//			do_n_times(stacks, sb, n);
//		else
//			do_n_times(stacks, ss, n);
//	}
//	if (op == push)
//	{
//		if (stack == a)
//			do_n_times(stacks, pa, n);
//		else
//			do_n_times(stacks, pb, n);
//	}
//	if (op == rotate)
//	{
//		if (stack == a)
//			do_n_times(stacks, ra, n);
//		else if (stack == b)
//			do_n_times(stacks, rb, n);
//		else
//			do_n_times(stacks, rr, n);
//	}
//	if (op == r_rotate)
//	{
//		if (stack == a)
//			do_n_times(stacks, rra, n);
//		else if (stack == b)
//			do_n_times(stacks, rrb, n);
//		else
//			do_n_times(stacks, rrr, n);
//	}
//}
//
t_opcount	*set_opcount(void)
{
	t_opcount *opcount;

	opcount = (t_opcount *) malloc(sizeof (t_opcount));
	opcount->sa_count = 0;
	opcount->sb_count = 0;
	opcount->ss_count = 0;
	opcount->pa_count = 0;
	opcount->pb_count = 0;
	opcount->ra_count = 0;
	opcount->rb_count = 0;
	opcount->rr_count = 0;
	opcount->rra_count = 0;
	opcount->rrb_count = 0;
	opcount->rrr_count = 0;
	return(opcount);
}
int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_opcount	*opcount;
	t_oplist	*oplist;

	// ALLOC THIS LATER
	oplist = NULL;
	if (argc == 1)	
	{
		ft_printf("argc is one, remove this later\n");
		exit (0);
	}
	if (argc == 2)
		exit(0);
	stacks = allocate_stacks(argc - 1);
	if (!stacks)
	{
		ft_printf("alloc failed");
		free_exit(stacks, 1);
	}
	fill_stack(stacks, argc - 1, &argv[1]);
	opcount = set_opcount();
	print_stack(stacks->a, stacks->len_a, 'a', 1);
	//print_stack(stacks->b, stacks->len_b, 'b', 1);
	//do_n_times(stacks, pb, 2);
	//pa(stacks);
	//pb(stacks);
	//sa(stacks);
	//sb(stacks);

	//ss(stacks);
	//ra(stacks);
	//rb(stacks);
	//rr(stacks);
	//rra(stacks);
	//rrb(stacks);
	//rrr(stacks);
	//print_stack(stacks->a, stacks->len_a, 'a', 1);
	//print_stack(stacks->b, stacks->len_b, 'b', 1);
//	quicksort(stacks, oplist, opcount);
	sort_three('a', stacks->a, stacks);
	print_stack(stacks->a, stacks->len_a, 'a', 1);
	free_exit(stacks, 0);
	return (0);
}
