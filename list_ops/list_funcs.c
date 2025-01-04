#include "../push_swap.h"

void	fill_stack(t_intlist *a, int count, char **numbers)
{
	int	i;

	i = 0;
	while (i < count)
	{
		a[i].element = ft_atoi(numbers[i]);
		a[i].next = &a[i + 1];
		i++;
	}
	a[i - 1].next = a;
}

t_stacks	*allocate_stacks(int count)
{
	t_intlist	*new_list_a;
	t_intlist	*new_list_b;
	t_stacks	*stacks;

	new_list_a = (t_intlist *) malloc(sizeof (t_intlist) * count);
	if (!new_list_a)
		return (NULL);
	new_list_b = (t_intlist *) malloc(sizeof (t_intlist) * count);
	if (!new_list_b)
	{
		free(new_list_a);
		return (NULL);
	}
	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
	{
		free(new_list_a);
		free(new_list_b);
		return (NULL);
	}
	stacks->a = new_list_a;
	stacks->b = new_list_b;
	stacks->a_len = count;
	stacks->b_len = 0;
	return (stacks);
}

void	free_all(t_stacks *stacks)
{
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}
//create node

//free node
// free list
// add one front
// add one back
