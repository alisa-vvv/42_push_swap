#include "push_swap.h"

void	sort_two(t_stacks *stacks, t_intlist *stack, e_op_stack a_b)
{
	const int el1 = stack->element;
	const int el2 = stack->next->element;
	
	if (el1 > el2)
		do_op(stacks, op_swap, a_b, 1);
}

void	sort_three(t_stacks *stacks, t_intlist *stack, e_op_stack a_b)
{
	const int el1 = stack->element;
	const int el2 = stack->next->element;
	const int el3 = stack->prev->element;
	
	if (el1 < el2 && el2 < el3)
		return ;
	if (el1 < el2 && el2 > el3)
		do_op(stacks, op_rrot, a_b, 1);
	if ((el1 > el2 && el2 > el3) || (el1 > el2 && el2 < el3 && el3 < el1))
		do_op(stacks, op_rot, a_b, 1);
	if ((el1 < el2 && el2 > el3 && el3 > el1) || (el1 > el2 && el2 > el3)
			|| (el1 > el2 && el2 < el3 && el3 > el1))
		do_op(stacks, op_swap, a_b, 1);
}

void	sort_small_stack(t_stacks *stacks, e_op_stack op_stack, int len)
{
	t_intlist	*sorted_stack;

	if (op_stack == stack_a)
		sorted_stack = stacks->a;
	else if (op_stack == stack_b)
		sorted_stack = stacks->b;
	if (len == 1)
		return ;
	else if (len == 2)
		sort_two(stacks, sorted_stack, op_stack);
	else if (len == 3)
		sort_three(stacks, sorted_stack, op_stack);
}

