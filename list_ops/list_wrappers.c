#include "../push_swap.h"

t_intlist *get_element_n(t_intlist *node, int n)
{
	while(n--)
	{
		if (!node->next)
			break ;
		node = node->next;
	}
	return (node);
}

void	switch_elements(t_intlist *node1, t_intlist *node2)
{
	t_intlist	*tmp;

	tmp = node1;
	node1 = node2;
	node2 = tmp;
}

