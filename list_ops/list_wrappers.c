/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   list_wrappers.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/01/07 18:42:06 by avaliull       #+#    #+#                */
/*   Updated: 2025/01/07 19:40:38 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_intlist *get_element_n(t_intlist *node, int n)
{
	while(--n)
		node = node->next;
	return (node);
}

void	swap_nodes(t_intlist *node1, t_intlist *node2)
{
	t_intlist	*tmp_next;

	tmp_next = node2->next;
	node2->next = node1;
	node1->next = tmp_next;
	node2->prev = node1->prev;
	node1->prev->next = node2;
	node1->prev = node2;
}

