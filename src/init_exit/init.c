#include "push_swap.h"
#include <unistd.h>
#include <limits.h>

static int	push_swap_atoi(t_stacks *stacks, const char *str)
{
	int		sign;
	long	tmp_n;
	int		str_len;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	str_len = 0;
	tmp_n = 0;
	while (str[str_len])
	{
		if (str[str_len] < '0' || str[str_len] > '9')
			free_exit(stacks, 1);
		tmp_n = tmp_n * 10 + str[str_len] - '0';
		if ((sign == 1 && tmp_n > INT_MAX) ||
			(sign == -1 && (-tmp_n < INT_MIN)))
			free_exit(stacks, 1);
		str_len++;
	}
	return (sign * (int) tmp_n);
}

static void	cmp_loop(t_stacks *stacks, t_intlist *node, int c, int cmp_c)
{
	int		element_num;
	int		i;
	int		cmp_element;

	element_num = 0;
	while (c--)
	{
		element_num++;
		if (element_num == c)
			return ;
		i = 0;
		while (i < element_num)
		{
			node = node->next;
			i++;
		}
		cmp_element = node->prev->element;
		cmp_c = stacks->len_a - element_num;
		while (cmp_c--)
		{
			if (cmp_element == node->element)
				free_exit(stacks, 1);
			node = node->next;
		}
	}
}

static void	check_dups(t_stacks *stacks, int count)
{
	if (count == 2)
	{
		if (stacks->a->element == stacks->a->next->element)
			free_exit(stacks, 1);
		return ;
	}
	cmp_loop(stacks, stacks->a, count, count);
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
	stacks->head_a = NULL;
	stacks->tail_a = NULL;
	stacks->head_b = NULL;
	stacks->tail_b = NULL;
	stacks->b = NULL;
	stacks->len_a = count;
	stacks->len_b = 0;
	return (stacks);
}
