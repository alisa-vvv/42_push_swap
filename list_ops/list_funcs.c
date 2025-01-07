/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   list_funcs.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: avaliull <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/01/07 18:41:58 by avaliull       #+#    #+#                */
/*   Updated: 2025/01/07 18:41:59 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

t_intlist	*add_node(int element)
{
	t_intlist	*new_node;

	new_node = (t_intlist *) malloc(sizeof(t_intlist));
	if (!new_node)
		return (NULL);
	new_node->element = element;
	return (new_node);
}

void	fill_stack(t_stacks *stacks, int count, char **numbers)
{
	int	i;
	t_intlist	*head;
	t_intlist	*new_node;

	stacks->a = add_node(ft_atoi(numbers[0]));
	if (!stacks->a)
		free_exit(stacks, 1);
	head = stacks->a;
	i = 1;
	while (i < count)
	{
		new_node = add_node(ft_atoi(numbers[i]));
		if (!new_node)
			free_exit(stacks, 1);
		stacks->a->next = new_node;
		stacks->a = new_node;
		i++;
	}
	stacks->a->next = head;
	stacks->a = head;
}

t_stacks	*allocate_stacks(int count)
{
	t_stacks	*stacks;

	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->len_a = count;
	stacks->len_b = 0;
	return (stacks);
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

//	make a function that clears the whole stack
//	error_chek is 0 on success, 1 on fail
void	free_exit(t_stacks *stacks, int error_check)
{
	t_intlist	*curr_node;
	t_intlist	*next_node;

	if (stacks->len_b)
	{
		curr_node = stacks->b;
		while (stacks->len_b)
		{
			next_node = curr_node->next;
			free_node(curr_node, &(stacks->len_b));
			curr_node = next_node;
		}
	}
	curr_node = stacks->a;
	if (error_check == 0)
	{
		while (stacks->len_a)
		{
			ft_printf("%d\n", curr_node->element);
			next_node = curr_node->next;
			free_node(curr_node, &(stacks->len_a));
			curr_node = next_node;
		}
	}
	else
	{
		while (stacks->len_a)
		{
			next_node = curr_node->next;
			free_node(curr_node, &(stacks->len_a));
			curr_node = next_node;
		}
		write(STDERR_FILENO, "Error\n", 6);
	}
	free(stacks);
	exit(error_check);
}
