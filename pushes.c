void	pa(t_stacks stacks)
{
	t_intlist	last_node;
	t_intlist	prev_node;

	if (stacks->len_b < 1)
		return ;
	if (stacks->len_a < 1)
	{
		stacks->a = stacks->b;
		stacks->a->next = stacks->a;
	}
	else
	{
		last_node = get_element_n(stacks->a, stakcs->len_a);
		
	}
}
