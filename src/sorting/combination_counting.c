#include "push_swap.h"

t_opcount	count_rr(t_opcount opcount)
{
	t_opcount	rr_opcount;

	rr_opcount = init_opcount();
	while (opcount.ra_count && opcount.rb_count)
	{
		opcount.ra_count--;
		opcount.rb_count--;
		rr_opcount.rr_count++;
	}
	rr_opcount.ra_count = opcount.ra_count;
	rr_opcount.rb_count = opcount.rb_count;
	return (rr_opcount);
}

t_opcount	count_rrr(t_opcount opcount)
{
	t_opcount	rrr_opcount;

	rrr_opcount = init_opcount();
	while (opcount.rra_count && opcount.rrb_count)
	{
		opcount.rra_count--;
		opcount.rrb_count--;
		rrr_opcount.rrr_count++;
	}
	rrr_opcount.rra_count = opcount.rra_count;
	rrr_opcount.rrb_count = opcount.rrb_count;
	return (rrr_opcount);
}

t_opcount	count_ra_rrb(t_opcount opcount)
{
	t_opcount	ra_rrb_opcount;

	ra_rrb_opcount = init_opcount();
	ra_rrb_opcount.ra_count = opcount.ra_count;
	ra_rrb_opcount.rrb_count = opcount.rrb_count;
	return (ra_rrb_opcount);
}

t_opcount	count_rb_rra(t_opcount opcount)
{
	t_opcount	rb_rra_count;

	rb_rra_count = init_opcount();
	rb_rra_count.rb_count = opcount.rb_count;
	rb_rra_count.rra_count = opcount.rra_count;
	return (rb_rra_count);
}

t_opcount	find_smallest_opcount(t_opcount opc)
{
	t_opcount	rr;
	t_opcount	rrr;
	t_opcount	ra_rrb;
	t_opcount	rb_rra;
	t_opcount	smallest;

	rr = count_rr(opc);
	//ft_printf("rr: %d\n", count_total(rr));
	rrr = count_rrr(opc);
	//ft_printf("rrr: %d\n", count_total(rrr));
	ra_rrb = count_ra_rrb(opc);
	//ft_printf("ra_rrb: %d\n", count_total(ra_rrb));
	rb_rra = count_rb_rra(opc);
	//ft_printf("rb_rra: %d\n", count_total(ra_rrb));
	smallest = rr;
	if (count_total(smallest) > count_total(rrr))
		smallest = rrr;
	if (count_total(smallest) > count_total(ra_rrb))
		smallest = ra_rrb;
	if (count_total(smallest) > count_total(rb_rra))
		smallest = rb_rra;
	//ft_printf("is this smallest? %d\n", count_total(smallest));
	return (smallest);
}
