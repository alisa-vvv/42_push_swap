#include "../push_swap.h"

void	swap(t_intlist *top_node, t_intlist *next_node, t_intlist *prev_node)
{
	t_intlist	*tmp_next;

	tmp_next = next_node->next;
	next_node->next->prev = top_node;
	next_node->next = top_node;
	top_node->next = tmp_next;
	next_node->prev = top_node->prev;
	prev_node->next = next_node;
	top_node->prev = next_node;
}
	
void	sa(t_stacks *stacks)
{
	t_intlist	*new_top;

	if (stacks->len_a <= 1)
	{
		ft_printf("sa\n");
		return ;
	}
	new_top = stacks->a->next;
	if (stacks->len_a != 2)
		swap(stacks->a, stacks->a->next, stacks->a->prev);
	stacks->a = new_top;
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	t_intlist	*new_top;

	if (stacks->len_b <= 1)
	{
		ft_printf("sb\n");
		return ;
	}
	new_top = stacks->b->next;
	if (stacks->len_b != 2)
		swap(stacks->b, stacks->b->next, stacks->b->prev);
	stacks->b = new_top;
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	t_intlist	*new_top;

	if (stacks->len_a > 1)
	{
		new_top = stacks->a->next;
		if (stacks->len_a != 2)
			swap(stacks->a, stacks->a->next, stacks->a->prev);
		stacks->a = new_top;
	}
	if (stacks->len_b > 1)
	{
		new_top = stacks->b->next;
		if (stacks->len_b != 2)
			swap(stacks->b, stacks->b->next, stacks->b->prev);
		stacks->b = new_top;
	}
	ft_printf("ss\n");
}

