#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 1)	
	{
		ft_printf("argc is one, remove this later\n");
		exit (0);
	}
	stacks = allocate_stacks(argc - 1);
	if (!stacks)
	{
		ft_printf("alloc failed");
		return (1);
	}
	fill_stack(stacks->a, argc - 1, argv + 1);
	ft_printf("mats is: %d\n", stacks->a->element);
	ft_printf("a coward: %d\n", stacks->a[1].element);
	ft_printf("this is cursed lmao: %d\n", stacks->a[1].next->element);
	free_all(stacks);
	return (0);
}
