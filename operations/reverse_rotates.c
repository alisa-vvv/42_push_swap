#include "../push_swap.h"

void	rra(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->prev;
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	if (stacks->len_b > 1)
		stacks->b = stacks->b->prev;
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->prev;
	if (stacks->len_b > 1)
		stacks->b = stacks->b->prev;
	ft_printf("rrr\n");
}
