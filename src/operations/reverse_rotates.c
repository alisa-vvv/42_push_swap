/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   reverse_rotates.c                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: avaliull <avaliull@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/11 15:14:15 by avaliull     #+#    #+#                  */
/*   Updated: 2025/02/11 15:14:16 by avaliull     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->prev;
	write(STDOUT_FILENO, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	if (stacks->len_b > 1)
		stacks->b = stacks->b->prev;
	write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->prev;
	if (stacks->len_b > 1)
		stacks->b = stacks->b->prev;
	write(STDOUT_FILENO, "rrr\n", 4);
}
