#include "push_swap.h"

//	REFACTOR THIS SO PRINT_STACK_A AND PTRINT_STACK_B ARE SEPARATE FUNCS
void	print_stack(t_intlist *stack, int len, char a_or_b, int with_prev_next)
{
	int	element_num;

	if (len == 1)
	{
		ft_printf("\n Stack %c has 1 element:\n", a_or_b);
		ft_printf("\tValue: %d\n", stack->element);
		ft_printf("\t\tPrev: %d\n", stack->prev->element);
		ft_printf("\t\tNext: %d\n", stack->next->element);
	}
	else if (len == 0)
	{
		ft_printf("\n Stack %c has no elements.\n\n", a_or_b);
		return ;
	}
	else
	{
		ft_printf("\n Printing stack %c with %d elements:\n", a_or_b, len);
		element_num = 1;
		if (with_prev_next)
		{
			while (element_num <= len)
			{
				ft_printf("    Element #%d:\n", element_num);
				ft_printf("\tValue: %d\n", stack->element);
				ft_printf("\t\tPrev: %d\n", stack->prev->element);
				ft_printf("\t\tNext: %d\n", stack->next->element);
				element_num++;
				stack = stack->next;
			}
		}
		else
		{
			while (element_num <= len)
			{
				ft_printf("    Element #%d:\n", element_num);
				ft_printf("\tValue: %d\n", stack->element);
				element_num++;
				stack = stack->next;
			}
		}
	}
	ft_printf(" End of stack %c.\n\n", a_or_b);
}

