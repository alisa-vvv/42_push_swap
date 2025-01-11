#include "../push_swap.h"

void	ra(t_stacks *stacks)
{
	if (stacks->len_a == 0)
		return ;
	stacks->a = stacks->a->next;
}

void	rb(t_stacks *stacks)
{
	if (stacks->len_b == 0)
		return ;
	stacks->b = stacks->b->next;
}

void	rr(t_stacks *stacks)
{
	if (stacks->len_a == 0)
		return ;
	stacks->a = stacks->a->next;
	if (stacks->len_b == 0)
		return ;
	stacks->b = stacks->b->next;
}
