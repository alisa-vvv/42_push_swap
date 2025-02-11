/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   exit.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: avaliull <avaliull@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/11 15:07:56 by avaliull     #+#    #+#                  */
/*   Updated: 2025/02/11 16:53:33 by avaliull     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

// prev<-node->next
// prev<-node->next
// prev<-node->next

#include "push_swap.h"

//	error_chek is 0 on success, 1 on fail
static void	list_clear(t_intlist *node)
{
	t_intlist	*cur_node;

	cur_node = node;
	while (node->prev)
	{
		cur_node = node;
		node = node->prev;
		if (cur_node->next)
			cur_node->next->prev = NULL;
		if (cur_node->prev)
			cur_node->prev->next = NULL;
		free(cur_node);
	}
	free(node);
}

static void	print_err_and_exit(int error_check)
{
	if (error_check)
		write(STDERR_FILENO, "Error\n", 6);
	exit(error_check);
}

void	free_exit(t_stacks *stacks, int error_check)
{
	if (!stacks)
		print_err_and_exit(error_check);
	if (stacks->b)
		list_clear(stacks->b);
	if (stacks->a)
		list_clear(stacks->a);
	free(stacks);
	print_err_and_exit(error_check);
}
