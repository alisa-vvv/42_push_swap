#include "../push_swap.h"

void	fill_stack(t_intlist *a, int count, char **numbers)
{
	int	i;
	t_intlist	*head;
	t_intlist	*new_node;

	head = a;
	a = add_node("FUNCTION TO CHECK VALIDITY -> FUNCTION TO CONVERT -> ALLOC");
	if (!a)
		free_exit(stacks, 1);
	head->next = a;
	i = 1;
	while (i < count)
	{
		new_node = add_node("FUNCTION TO CHECK VALIDITY -> FUNCTION TO CONVERT -> ALLOC");
		if (!new_node)
			free_exit(stacks, 1);
		a->next = new_node;
		a = new_node;
	}
	a->next = head;
}

t_stacks	*allocate_stacks(int count)
{
	t_stacks	*stacks;

	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a_len = count;
	stacks->b_len = 0;
	return (stacks);
}

void	free_node(t_intlist *prev, t_intlist *node, int *len)
{
	t_intlist	tmp_node;

	prev->next = node->next;
	(*len)--;
	free(node);
}

t_intlist	*add_node(int element)
{
	t_intlist	*new_node;

	new_node = (t_intlist *) malloc(sizeof(t_intlist));
	if (!new_node)
		return (NULL);
	new_node->element = element;
	return (new_node);
}

//	error_chek is 0 on success, 1 on fail
void	free_exit(t_stacks *stacks, int error_check)
{
	("loop to free both nodes");
	free(stacks);
// HERE, CHECK HOW TO USE A MACRO FOR STDERR INSTAD OF A NUMBER MAYBE
	if (error == 1)
		write(2, "Error\n", 6);
	exit (error_check);
}
//create node

//free node
// free list
// add one front
// add one back
