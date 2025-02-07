#include "push_swap.h"

t_opcount	check_cand_opcount_a(t_stacks *stacks, t_intlist *cand)
{
	t_opcount	pot_opcount;

	pot_opcount = init_opcount();
	count_to_b(stacks, &pot_opcount, cand);
	count_from_a(stacks->a, &pot_opcount, cand);
	pot_opcount = find_smallest_opcount(pot_opcount);
	return (pot_opcount);
}

int	cand_rev_a(t_stacks *stacks, t_opcount *opc, t_intlist **cand, int tot)
{
	int			steps;
	t_intlist	*tmp_cand;
	t_opcount	tmp_opcount;
	int			pot_tot;

	if (tot <= stacks->len_a)
		steps = tot;
	else
		steps = stacks->len_a;
	tmp_cand = stacks->a;
	while (steps-- > 0)
	{
		tmp_cand = tmp_cand->prev;
		tmp_opcount = check_cand_opcount_a(stacks, tmp_cand);
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

int	cand_obv_a(t_stacks *stacks, t_opcount *opc, t_intlist **cand, int tot)
{
	int			steps;
	t_intlist	*tmp_cand;
	t_opcount	tmp_opcount;
	int			pot_tot;

	if (tot <= stacks->len_a)
		steps = tot;
	else
		steps = stacks->len_a;
	tmp_cand = stacks->a;
	while (steps-- > 0)
	{
		tmp_cand = tmp_cand->next;
		tmp_opcount = check_cand_opcount_a(stacks, tmp_cand);
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

t_intlist *find_cand_a(t_stacks *stacks, t_opcount *pot_opcount, int cur_tot)
{
	t_intlist	*pot_candidate;
	int			pot_tot;
	t_opcount	new_opcount;
	
	pot_candidate = NULL;
	new_opcount = init_opcount();
	pot_tot = cand_obv_a(stacks, &new_opcount, &pot_candidate, cur_tot);
	if (pot_candidate)
		cur_tot = pot_tot;
	cand_rev_a(stacks, &new_opcount, &pot_candidate, cur_tot);
	if (pot_candidate)
		*pot_opcount = new_opcount;
	return (pot_candidate);
}
