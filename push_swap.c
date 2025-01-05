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
	ft_printf("el1_a: %d\n", stacks->a->element);
	ft_printf("el2_a: %d\n", stacks->a->next->element);
	ft_printf("el3_a: %d\n", stacks->a->next->next->element);
	ft_printf("next after last: %d\n", stacks->a[2].next->element);
	ss(stacks);
	ft_printf("el1_a: %d\n", stacks->a->element);
	ft_printf("el2_a: %d\n", stacks->a->next->element);
	ft_printf("el3_a: %d\n", stacks->a->next->next->element);
	ft_printf("next after last: %d\n", stacks->a->next->next->next->element);
	free_all(stacks);
	return (0);
}
