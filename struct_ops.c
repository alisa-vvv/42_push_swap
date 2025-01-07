#include "push_swap.h"
#include <unistd.h>

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
