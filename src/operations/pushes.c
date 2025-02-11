/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   pushes.c                                          :+:    :+:             */
/*                                                    +:+                     */
/*   By: avaliull <avaliull@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/11 15:13:57 by avaliull     #+#    #+#                  */
/*   Updated: 2025/02/11 19:36:22 by avaliull     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_intlist	*push(t_intlist *src, t_intlist *dst, int len_src, int len_dst)
{
	t_intlist	*src_prev;
	t_intlist	*src_next;

	if (len_src > 1)
	{
		src_prev = src->prev;
		src_next = src->next;
		src_prev->next = src->next;
		src_next->prev = src->prev;
	}
	if (len_dst == 0)
	{
		dst = src;
		dst->next = dst;
		dst->prev = dst;
	}
	else
	{
		src->next = dst;
		src->prev = dst->prev;
		dst->prev->next = src;
		dst->prev = src;
		dst = src;
	}
	return (dst);
}

void	pa(t_stacks *stacks)
{
	t_intlist	*b_next;

	if (stacks->len_b == 0)
		return ;
	b_next = stacks->b->next;
	stacks->a = push(stacks->b, stacks->a, stacks->len_b, stacks->len_a);
	stacks->len_a++;
	stacks->len_b--;
	if (stacks->len_b != 0)
		stacks->b = b_next;
	else
		stacks->b = NULL;
	write(STDOUT_FILENO, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	t_intlist	*a_next;

	if (stacks->len_a == 0)
		return ;
	a_next = stacks->a->next;
	stacks->b = push(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
	stacks->len_b++;
	stacks->len_a--;
	if (stacks->len_a != 0)
		stacks->a = a_next;
	else
		stacks->a = NULL;
	write(STDOUT_FILENO, "pb\n", 3);
}
