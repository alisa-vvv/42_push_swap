/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   list_funcs.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/01/07 18:41:58 by avaliull       #+#    #+#                */
/*   Updated: 2025/01/07 19:33:11 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_intlist	*add_node(int element)
{
	t_intlist	*new_node;

	new_node = (t_intlist *) malloc(sizeof(t_intlist));
	if (!new_node)
		return (NULL);
	new_node->element = element;
	return (new_node);
}

void	free_node(t_intlist *node, int *len)
{
	t_intlist	*prev_node;

	prev_node = node;
	while(prev_node->next != node)
		prev_node = prev_node->next;
	prev_node->next = node->next;
	(*len)--;
	free(node);
}

//	make a function that clears the whole list
