#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

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
	free_exit(stacks, 0);
	return (0);
}
