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

void	execute_operations(t_stacks *stacks, t_opcount ops, e_op_stack dst)
{
	if (ops.rr_count)
		do_op(stacks, op_rot, both, ops.rr_count);
	if (ops.rrr_count)
		do_op(stacks, op_rrot, both, ops.rrr_count);
	if (ops.ra_count)
		do_op(stacks, op_rot, stack_a, ops.ra_count);
	if (ops.rb_count)
		do_op(stacks, op_rot, stack_b, ops.rb_count);
	if (ops.rra_count)
		do_op(stacks, op_rrot, stack_a, ops.rra_count);
	if (ops.rrb_count)
		do_op(stacks, op_rrot, stack_b, ops.rrb_count);
	do_op(stacks, op_push, dst, 1);
}

