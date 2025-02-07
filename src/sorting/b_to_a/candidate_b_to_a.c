#include "push_swap.h"

t_intlist *find_cand_place_a(t_stacks *stacks, int cand_val, int len)
{
	t_intlist	*cur_node;

	if (cand_val < stacks->head_a->element || cand_val > stacks->tail_a->element)
	{
		return (stacks->head_a);
	}
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

