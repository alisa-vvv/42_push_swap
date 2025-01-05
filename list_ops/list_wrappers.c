#include "../push_swap.h"

t_intlist *get_element_n(t_intlist *node, int n)
{
	while(--n)
		node = node->next;
	return (node);
}

void	switch_elements(t_intlist *prev, t_intlist *node1, t_intlist *node2)
{
	t_intlist	*tmp_next;

	tmp_next = node2->next;
	node2->next = node1;
	node1->next = tmp_next;
	prev->next = node2;
}

