/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   test_funcs.c                                      :+:    :+:             */
/*                                                    +:+                     */
/*   By: avaliull <avaliull@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/12 12:50:35 by avaliull     #+#    #+#                  */
/*   Updated: 2025/02/12 12:50:38 by avaliull     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	REFACTOR THIS SO PRINT_STACK_A AND PTRINT_STACK_B ARE SEPARATE FUNCS
//	or don't lol
//print_stack(stacks->a, stacks->len_a, a, 1);
//print_stack(stacks->b, stacks->len_b, b, 1);
//void	print_stack(t_intlist *stack, int len, char a_or_b, int with_prev_next)
//{
//	int	element_num;
//
//	if (len == 1)
//	{
//		ft_printf("\n Stack %c has 1 element:\n", a_or_b);
//		ft_printf("\tValue: %d\n", stack->element);
//		ft_printf("\t\tPrev: %d\n", stack->prev->element);
//		ft_printf("\t\tNext: %d\n", stack->next->element);
//	}
//	else if (len == 0)
//	{
//		ft_printf("\n Stack %c has no elements.\n\n", a_or_b);
//		return ;
//	}
//	else
//	{
//		ft_printf("\n Printing stack %c with %d elements:\n", a_or_b, len);
//		element_num = 1;
//		if (with_prev_next)
//		{
//			while (element_num <= len)
//			{
//				ft_printf("    Element #%d:\n", element_num);
//				ft_printf("\tValue: %d\n", stack->element);
//				ft_printf("\t\tPrev: %d\n", stack->prev->element);
//				ft_printf("\t\tNext: %d\n", stack->next->element);
//				element_num++;
//				stack = stack->next;
//			}
//		}
//		else
//		{
//			while (element_num <= len)
//			{
//				ft_printf("    Element #%d:\n", element_num);
//				ft_printf("\tValue: %d\n", stack->element);
//				element_num++;
//				stack = stack->next;
//			}
//		}
//	}
//	ft_printf(" End of stack %c.\n\n", a_or_b);
//}
//
