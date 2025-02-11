/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   rotation_counting.c                               :+:    :+:             */
/*                                                    +:+                     */
/*   By: avaliull <avaliull@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/11 15:17:07 by avaliull     #+#    #+#                  */
/*   Updated: 2025/02/11 15:45:47 by avaliull     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rev_rots(t_intlist *node, const t_intlist *target)
{
	int	count;

	count = 0;
	while (node != target)
	{
		count++;
		node = node->prev;
	}
	return (count);
}

int	count_obv_rots(t_intlist *node, const t_intlist *target)
{
	int	count;

	count = 0;
	while (node != target)
	{
		count++;
		node = node->next;
	}
	return (count);
}
