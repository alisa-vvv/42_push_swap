#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_intlist	*next_b;
	t_intlist	*prev_b;

	if (stacks->len_b == 0)
		return ;
	if (stacks->len_b > 1)
	{
		prev_b = stacks->b->prev;
		next_b = stacks->b->next;
		prev_b->next = next_b;
		next_b->prev = prev_b;
	}
	if (stacks->len_a == 0)
	{
		stacks->a = stacks->b;
		stacks->a->next = stacks->a;
		stacks->a->prev = stacks->a;
	}
	else
	{
		stacks->b->next = stacks->a;
		stacks->b->prev = stacks->a->prev;
		stacks->a->prev->next = stacks->b;
		stacks->a->prev = stacks->b;
		stacks->a = stacks->b;
	}
	stacks->len_a++;
	stacks->len_b--;
	if (stacks->len_b != 0)
		stacks->b = next_b;
	else
		stacks->b = NULL;
}

void	pb(t_stacks *stacks)
{
	t_intlist	*next_a;
	t_intlist	*prev_a;

	if (stacks->len_a == 0)
		return ;
	if (stacks->len_a > 1)
	{
		prev_a = stacks->a->prev;
		next_a = stacks->a->next;
		prev_a->next = next_a;
		next_a->prev = prev_a;
	}
	if (stacks->len_b == 0)
	{
		stacks->b = stacks->a;
		stacks->b->next = stacks->b;
		stacks->b->prev = stacks->b;
	}
	else
	{
		stacks->a->next = stacks->b;
		stacks->a->prev = stacks->b->prev;
		stacks->b->prev->next = stacks->a;
		stacks->b->prev = stacks->a;
		stacks->b = stacks->a;
	}
	stacks->len_b++;
	stacks->len_a--;
	if (stacks->len_a != 0)
		stacks->a = next_a;
	else
		stacks->a = NULL;
}
