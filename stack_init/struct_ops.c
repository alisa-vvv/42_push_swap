#include "../push_swap.h"
#include <unistd.h>
#include <limits.h>

static int	push_swap_atoi(t_stacks *stacks, const char *str)
{
	int	sign;
	long		temp_long;
	int			newint;
	int		str_len;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	str_len = 0;
	temp_long = 0;
	while (str[str_len])
	{
		if (str[str_len] < '0' || str[str_len] > '9')
			free_exit(stacks, 1);
		temp_long = temp_long * 10 + str[str_len] - '0';
		if (temp_long > INT_MAX)
			free_exit(stacks, 1);
		str_len++;
	}
	newint = (int) temp_long;
	return (sign * newint);
}

static void	check_dups(t_stacks *stacks, int count)
{
	int		comp_element;
	t_intlist	*comp_node;
	int		comp_count;
	int		element_num;
	int		i;

	if (count == 2)
	{
		if (stacks->a->element == stacks->a->next->element)
			free_exit(stacks, 1);
		return ;
	}
	comp_count = count;
	comp_node = stacks->a;
	element_num = 0;
	while (count--)
	{
		element_num++;
		if (element_num == count)
			return ;
		i = 0;
		while (i < element_num)
		{
			comp_node = comp_node->next;
			i++;
		}
		comp_element = comp_node->prev->element;
		comp_count = stacks->len_a - element_num;
		ft_printf("current comp_element: %d\n", comp_element);
		while (comp_count--)
		{
			if (comp_element == comp_node->element)
				free_exit(stacks, 1);
			ft_printf("current comp_node: %d\n", comp_node->element);
			comp_node = comp_node->next;
		}
	}
}

void	fill_stack(t_stacks *stacks, int count, char **numbers)
{
	int	i;
	t_intlist	*head;
	t_intlist	*new_node;

	stacks->a = add_node(push_swap_atoi(stacks, numbers[0]));
	if (!stacks->a)
		free_exit(stacks, 1);
	head = stacks->a;
	i = 1;
	while (i < count)
	{
		new_node = add_node(push_swap_atoi(stacks, numbers[i]));
		if (!new_node)
			free_exit(stacks, 1);
		stacks->a->next = new_node;
		new_node->prev = stacks->a;
		stacks->a = new_node;
		new_node->next = NULL;
		i++;
	}
	head->prev = stacks->a;
	stacks->a->next = head;
	stacks->a = head;
	check_dups(stacks, count);
}

t_stacks	*allocate_stacks(int count)
{
	t_stacks	*stacks;

	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->len_a = count;
	stacks->len_b = 0;
	return (stacks);
}
