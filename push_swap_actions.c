#include "push_swap.h"

void	aa(t_stacks stacks)
{
	if (stacks.a_len <= 1)
		return ;
	switch_elements(stacks.a, stacks.a->next);
}

