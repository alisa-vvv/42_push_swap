#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_intlist	*new_head;
	t_intlist	*last_node;

	if (stacks->len_a <= 1)
		return ;
	new_head = stacks->a->next;
	last_node = get_element_n(stacks->a, stacks->len_a);
	switch_elements(last_node, stacks->a, stacks->a->next);
	stacks->a = new_head;
}

void	sb(t_stacks *stacks)
{
	t_intlist	*new_head;
	t_intlist	*last_node;

	if (stacks->len_b <= 1)
		return ;
	new_head = stacks->b->next;
	last_node = get_element_n(stacks->b, stacks->len_b);
	switch_elements(last_node, stacks->b, stacks->b->next);
	stacks->b = new_head;
}

void	ss(t_stacks *stacks)
{
	t_intlist	*new_head;
	t_intlist	*last_node;

	if (stacks->len_a > 1)
	{
		ft_printf("testing sa in ss\n");
		new_head = stacks->a->next;
		last_node = get_element_n(stacks->a, stacks->len_a);
		switch_elements(last_node, stacks->a, stacks->a->next);
		stacks->a = new_head;
	}
	if (stacks->len_b > 1)
	{
		ft_printf("testing sb in ss\n");
		new_head = stacks->b->next;
		last_node = get_element_n(stacks->b, stacks->len_b);
		switch_elements(last_node, stacks->b, stacks->b->next);
		stacks->b = new_head;
	}
}
