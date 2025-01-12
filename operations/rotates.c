#include "../push_swap.h"

void	ra(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->next;
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	if (stacks->len_b > 1)
		stacks->b = stacks->b->next;
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->next;
	if (stacks->len_b > 1)
		stacks->b = stacks->b->next;
	ft_printf("rr\n");
}
