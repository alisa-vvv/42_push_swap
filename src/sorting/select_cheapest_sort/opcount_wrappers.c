/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   opcount_wrappers.c                                :+:    :+:             */
/*                                                    +:+                     */
/*   By: avaliull <avaliull@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/02/11 15:16:32 by avaliull     #+#    #+#                  */
/*   Updated: 2025/02/11 15:48:36 by avaliull     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_total(t_opcount opcount)
{
	int	total;

	total = 0;
	total += opcount.sa_count;
	total += opcount.sb_count;
	total += opcount.ss_count;
	total += opcount.pa_count;
	total += opcount.pb_count;
	total += opcount.ra_count;
	total += opcount.rb_count;
	total += opcount.rr_count;
	total += opcount.rra_count;
	total += opcount.rrb_count;
	total += opcount.rrr_count;
	return (total);
}

t_opcount	init_opcount(void)
{
	t_opcount	opcount;

	opcount.sa_count = 0;
	opcount.sb_count = 0;
	opcount.ss_count = 0;
	opcount.pa_count = 0;
	opcount.pb_count = 0;
	opcount.ra_count = 0;
	opcount.rb_count = 0;
	opcount.rr_count = 0;
	opcount.rra_count = 0;
	opcount.rrb_count = 0;
	opcount.rrr_count = 0;
	return (opcount);
}
