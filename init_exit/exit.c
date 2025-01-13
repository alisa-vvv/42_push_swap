#include "../push_swap.h"

//	delete the part that uses pointer to len, it's useless
//	error_chek is 0 on success, 1 on fail
static void	list_clear(t_intlist *node, int len)
{
	t_intlist	*next_node;

	while (len)
	{
		if (!node->next)
			return ;
		next_node = node->next;
		free_node(node, &len);
		node = next_node;
	}
}

static void	print_err_and_exit(int error_check)
{
	if (error_check)
		write(STDERR_FILENO, "Error\n", 6);
	if (!error_check)
		ft_printf("no error (remember to delete this)\n");
	exit(error_check);

}
void	free_exit(t_stacks *stacks, int error_check)
{
	if (!stacks)
		print_err_and_exit(error_check);
	if (stacks->b)
		list_clear(stacks->b, stacks->len_b);
	if (stacks->a)
		list_clear(stacks->a, stacks->len_a);
	free(stacks);
	print_err_and_exit(error_check);
}
