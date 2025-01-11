#include "../push_swap.h"

void	rra(t_stacks *stacks)
{
	if (stacks->len_a <= 1)
		return ;
	stacks->a = stacks->a->prev;
}

void	rrb(t_stacks *stacks)
{
	if (stacks->len_b <= 1)
		return ;
	stacks->b = stacks->b->prev;
}

void	rrr(t_stacks *stacks)
{
	if (stacks->len_a <= 1)
		return ;
	stacks->a = stacks->a->prev;
	if (stacks->len_b <= 1)
		return ;
	stacks->b = stacks->b->prev;
}
