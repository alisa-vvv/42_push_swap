#include "push_swap.h"

void	int_cpy(int *dest, int *src, size_t n)
{
	while (n--)
		dest[n] = src[n];
}

int	find_median(t_med_arrs *arrs, const int len, const int med_pos)
{
	const int	pivot = arrs->elems[len / 2];
	int			i;
	int			small_count;
	int			big_count;
	int			pos;

	small_count = 0;
	big_count = 0;
	i = 0;
	while (i < len)
	{
		if (arrs->elems[i] < pivot)
			arrs->lows[small_count++] = arrs->elems[i];
		else if (arrs->elems[i] > pivot)
			arrs->highs[big_count++] = arrs->elems[i];
		i++;
	}
	pos = small_count + 1;
	if (pos < med_pos)
	{
		int_cpy(arrs->elems, arrs->highs, big_count);
		return (find_median(arrs, big_count, med_pos - (small_count + 1)));
	}
	else if (pos > med_pos)
	{
		int_cpy(arrs->elems, arrs->lows, small_count);
		return (find_median(arrs, small_count, med_pos));
	}
	return (pivot);
}

void	put_part_on_arr(t_med_arrs *med_arrs, t_intlist *top_node, int count)
{
	while (count--)
	{
		med_arrs->elems[count] = top_node->element;
		top_node = top_node->next;
	}
}

t_med_arrs *free_med_arrs(t_med_arrs *med_arrs)
{
	if (med_arrs->elems)
		free(med_arrs->elems);
	if (med_arrs->lows)
		free(med_arrs->lows);
	if (med_arrs->highs)
		free(med_arrs->highs);
	free(med_arrs);
	return (NULL);
}

t_med_arrs	*alloc_med_arrs(t_intlist *top_node, int count)
{
	t_med_arrs	*med_arrs;

	med_arrs = (t_med_arrs *) malloc(sizeof(t_med_arrs));
	if (!med_arrs)
		return (NULL);
	med_arrs->elems = (int *) malloc(count * sizeof(int));
	if (!med_arrs->elems)
		return (free_med_arrs(med_arrs));
	med_arrs->lows = (int *) malloc(count * sizeof(int));
	if (!med_arrs->lows)
		return (free_med_arrs(med_arrs));
	med_arrs->highs = (int *) malloc(count * sizeof(int));
	if (!med_arrs->highs)
		return (free_med_arrs(med_arrs));
	put_part_on_arr(med_arrs, top_node, count);
	return (med_arrs);
}

