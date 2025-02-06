#include "push_swap.h"

int	find_lis(t_stacks *stacks, t_intlist **top, t_intlist *cur_node, int len)
{
	t_intlist	*longest_start;
	int			longest_len;
	t_intlist	*cur_start;
	int			cur_len;
	int			i;

	longest_len = 1;
	longest_start = cur_node;
	i = 0;
	while (i < len)
	{
		cur_len = 1;
		cur_start = cur_node;
		while (cur_node->next->element > cur_node->element)
		{
			cur_len++;
			cur_node = cur_node->next;
		}
		i++;
		if (cur_len > longest_len)
		{
			cur_node = cur_node->next;
			longest_start = cur_start;
			longest_len = cur_len;
		}
		else
			cur_node = get_element_n(stacks, stack_a, i);
	}
	*top = longest_start;
	return (longest_len);
}
