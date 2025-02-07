#include "push_swap.h"

t_intlist *find_cand_place_b(t_stacks *stacks, int cand_val, int len)
{
	t_intlist	*cur_node;

	if (cand_val > stacks->tail_b->element || cand_val < stacks->head_b->element)
	{
		return (stacks->tail_b);
	}
	cur_node = stacks->tail_b;
	while (len--)
	{
		if (cand_val > cur_node->element)
			break ;
		cur_node = cur_node->next;
	}
	return (cur_node);
}

//t_intlist *find_cand_place_b(t_stacks *stacks, int cand_val, int len)
//{
//	t_intlist	*cur_node;
//
//	if (cand_val < stacks->head_b->element || cand_val > stacks->tail_b->element)
//	{
//		return (stacks->head_b);
//	}
//	cur_node = stacks->head_b;
//	while (len--)
//	{
//		if (cand_val < cur_node->element)
//			break ;
//		cur_node = cur_node->next;
//	}
//	return (cur_node);
//}

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
