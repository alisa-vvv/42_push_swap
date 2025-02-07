#include "push_swap.h"

t_opcount	check_cand_opcount_b(t_stacks *stacks, t_intlist *cand)
{
	t_opcount	pot_opcount;

	pot_opcount = init_opcount();
	count_to_a(stacks, &pot_opcount, cand);
	count_from_b(stacks->b, &pot_opcount, cand);
	pot_opcount = find_smallest_opcount(pot_opcount);
	return (pot_opcount);
}

int	cand_rev_b(t_stacks *stacks, t_opcount *opc, t_intlist **cand, int tot)
{
	int			steps;
	t_intlist	*tmp_cand;
	t_opcount	tmp_opcount;
	int			pot_tot;

	if (tot <= stacks->len_b)
		steps = tot;
	else
		steps = stacks->len_b;
	tmp_cand = stacks->b;
	while (steps-- > 0)
	{
		tmp_cand = tmp_cand->prev;
		tmp_opcount = check_cand_opcount_b(stacks, tmp_cand);
		pot_tot = count_total(tmp_opcount);
		if (pot_tot < tot)
		{
			steps -= (tot - pot_tot);
			*cand = tmp_cand;
			*opc = tmp_opcount;
		}
	}
	return (pot_tot);
}

int	cand_obv_b(t_stacks *stacks, t_opcount *opc, t_intlist **cand, int tot)
{
	int			steps;
	t_intlist	*tmp_cand;
	t_opcount	tmp_opcount;
	int			pot_tot;

	if (tot <= stacks->len_b)
		steps = tot;
	else
		steps = stacks->len_b;
	tmp_cand = stacks->b;
	while (steps-- > 0)
	{
		tmp_cand = tmp_cand->next;
		tmp_opcount = check_cand_opcount_b(stacks, tmp_cand);
		pot_tot = count_total(tmp_opcount);
		if (pot_tot < tot)
		{
			steps -= (tot - pot_tot);
			*cand = tmp_cand;
			*opc = tmp_opcount;
		}
	}
	return (pot_tot);
}

t_intlist *find_cand_b(t_stacks *stacks, t_opcount *pot_opcount, int cur_tot)
{
	t_intlist	*pot_candidate;
	int			pot_tot;
	t_opcount	new_opcount;
	
	pot_candidate = NULL;
	new_opcount = init_opcount();
	pot_tot = cand_obv_b(stacks, &new_opcount, &pot_candidate, cur_tot);
	if (pot_candidate)
		cur_tot = pot_tot;
	cand_rev_b(stacks, &new_opcount, &pot_candidate, cur_tot);
	if (pot_candidate)
		*pot_opcount = new_opcount;
	return (pot_candidate);
}
