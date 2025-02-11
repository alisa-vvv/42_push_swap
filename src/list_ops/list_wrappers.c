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

#include "push_swap.h"

t_intlist	*add_node(int element)
{
	t_intlist	*new_node;

	new_node = (t_intlist *) malloc(sizeof(t_intlist));
	if (!new_node)
		return (NULL);
	new_node->element = element;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_intlist	*get_element_n(t_stacks *stacks, t_op_stack stack, int n)
{
	t_intlist	*node;

	if (stack == stack_a)
		node = stacks->a;
	else if (stack == stack_b)
		node = stacks->b;
	while (--n)
		node = node->next;
	return (node);
}
