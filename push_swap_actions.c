#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_intlist	*new_head;

	if (stacks->len_a <= 1)
		return ;
	new_head = stacks->a->next;
	swap_nodes(stacks->a, stacks->a->next);
	stacks->a = new_head;
}

void	sb(t_stacks *stacks)
{
	t_intlist	*new_head;

	if (stacks->len_b <= 1)
		return ;
	new_head = stacks->b->next;
	swap_nodes(stacks->b, stacks->b->next);
	stacks->b = new_head;
}

void	ss(t_stacks *stacks)
{
	t_intlist	*new_head;

	if (stacks->len_a > 1)
	{
		ft_printf("testing sa in ss\n");
		new_head = stacks->a->next;
		swap_nodes(stacks->a, stacks->a->next);
		stacks->a = new_head;
	}
	if (stacks->len_b > 1)
	{
		ft_printf("testing sb in ss\n");
		new_head = stacks->b->next;
		swap_nodes(stacks->b, stacks->b->next);
		stacks->b = new_head;
	}
}
