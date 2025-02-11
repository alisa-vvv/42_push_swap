/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   candidate_a_to_b.c                                :+:    :+:             */
/*                                                    +:+                     */
/*   By: avaliull <avaliull@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/11 15:22:19 by avaliull     #+#    #+#                  */
/*   Updated: 2025/02/11 17:23:49 by avaliull     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intlist	*find_cand_place_b(t_stacks *stacks, int cand_val, int len)
{
	t_intlist	*cur_node;

	if (cand_val > stacks->tail_b->element
		|| cand_val < stacks->head_b->element)
		return (stacks->tail_b);
	cur_node = stacks->tail_b;
	while (len--)
	{
		cur_node = cur_node->next;
		if (cand_val > cur_node->element)
			break ;
	}
	return (cur_node);
}

void	count_to_b(t_stacks *stacks, t_opcount *opc, t_intlist *cand)
{
	t_intlist	*cand_place;

	cand_place = find_cand_place_b(stacks, cand->element, stacks->len_b);
	opc->rb_count = count_obv_rots(stacks->b, cand_place);
	opc->rrb_count = count_rev_rots(stacks->b, cand_place);
}

void	count_from_a(t_intlist *a, t_opcount *opc, t_intlist *cand)
{
	opc->ra_count = count_obv_rots(a, cand);
	opc->rra_count = count_rev_rots(a, cand);
}

void	cheapest_to_b(t_stacks *stacks)
{
	t_opcount	opcount;
	t_opcount	pot_opcount;
	t_intlist	*candidate;
	t_intlist	*pot_candidate;

	while (stacks->len_a > 3)
	{
		candidate = stacks->a;
		opcount = check_cand_opcount_a(stacks, candidate);
		pot_opcount = init_opcount();
		pot_candidate = find_cand_a(stacks, &pot_opcount, count_total(opcount));
		if (pot_candidate)
			opcount = pot_opcount;
		execute_operations(stacks, opcount, stack_b);
		if (stacks->b->element < stacks->head_b->element)
			stacks->head_b = stacks->b;
		if (stacks->b->element > stacks->tail_b->element)
			stacks->tail_b = stacks->b;
	}
}
