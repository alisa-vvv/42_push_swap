/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   candidate_b_to_a.c                                :+:    :+:             */
/*                                                    +:+                     */
/*   By: avaliull <avaliull@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/11 15:28:15 by avaliull     #+#    #+#                  */
/*   Updated: 2025/02/11 17:24:13 by avaliull     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intlist	*find_cand_place_a(t_stacks *stacks, int cand_val, int len)
{
	t_intlist	*cur_node;

	if (cand_val < stacks->head_a->element
		|| cand_val > stacks->tail_a->element)
		return (stacks->head_a);
	cur_node = stacks->head_a;
	while (len--)
	{
		if (cand_val < cur_node->element)
			break ;
		cur_node = cur_node->next;
	}
	return (cur_node);
}

void	count_to_a(t_stacks *stacks, t_opcount *opc, t_intlist *cand)
{
	t_intlist	*cand_place;

	cand_place = find_cand_place_a(stacks, cand->element, stacks->len_a);
	opc->ra_count = count_obv_rots(stacks->a, cand_place);
	opc->rra_count = count_rev_rots(stacks->a, cand_place);
}

void	count_from_b(t_intlist *b, t_opcount *opc, t_intlist *cand)
{
	opc->rb_count = count_obv_rots(b, cand);
	opc->rrb_count = count_rev_rots(b, cand);
}

void	cheapest_to_a(t_stacks *stacks)
{
	t_intlist	*target;
	int			obv_rots;
	int			rev_rots;

	while (stacks->len_b)
	{
		target = find_cand_place_a(stacks, stacks->b->element, stacks->len_a);
		obv_rots = count_obv_rots(stacks->a, target);
		rev_rots = count_rev_rots(stacks->a, target);
		if (obv_rots < rev_rots)
			do_op(stacks, op_rot, stack_a, obv_rots);
		else
			do_op(stacks, op_rrot, stack_a, rev_rots);
		do_op(stacks, op_push, stack_a, 1);
		if (stacks->a->element < stacks->head_a->element)
			stacks->head_a = stacks->a;
		if (stacks->a->element > stacks->tail_a->element)
			stacks->tail_a = stacks->a;
	}
}
