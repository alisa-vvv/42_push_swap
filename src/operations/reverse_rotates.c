#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->prev;
	write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	if (stacks->len_b > 1)
		stacks->b = stacks->b->prev;
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->prev;
	if (stacks->len_b > 1)
		stacks->b = stacks->b->prev;
	write(STDOUT_FILENO, "rrr\n", 4);
}
