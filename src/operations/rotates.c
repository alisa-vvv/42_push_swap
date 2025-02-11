#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->next;
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stacks *stacks)
{
	if (stacks->len_b > 1)
		stacks->b = stacks->b->next;
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->next;
	if (stacks->len_b > 1)
		stacks->b = stacks->b->next;
	write(STDOUT_FILENO, "rr\n", 3);
}
