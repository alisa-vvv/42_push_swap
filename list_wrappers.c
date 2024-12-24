#include "push_swap.h"

t_list get_element_n(t_list *node, int n)
{
	while(n--)
	{
		if (!node->next)
			break ;
		node = node->next;
	}
	return (node);
}

void	switch_elements(t_list *node1, t_list *node2)
{
	t_list	*tmp;

	tmp = node1;
	node1 = node2;
	node2 = tmp;
}

void	push_element(t_list *node1, t_list *node2)
{
	
}
