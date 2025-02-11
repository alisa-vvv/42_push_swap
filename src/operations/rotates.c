/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   rotates.c                                         :+:    :+:             */
/*                                                    +:+                     */
/*   By: avaliull <avaliull@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/11 15:14:24 by avaliull     #+#    #+#                  */
/*   Updated: 2025/02/11 20:05:02 by avaliull     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->next;
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stacks *stacks)
{
	if (stacks->len_b > 1)
		stacks->b = stacks->b->next;
	write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_stacks *stacks)
{
	if (stacks->len_a > 1)
		stacks->a = stacks->a->next;
	if (stacks->len_b > 1)
		stacks->b = stacks->b->next;
	write(STDOUT_FILENO, "rr\n", 3);
}
