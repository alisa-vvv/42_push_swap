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
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	free_node(t_intlist *node, int *len)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	(*len)--;
	free(node);
}

//	make a function that clears the whole list
