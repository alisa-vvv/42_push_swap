/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:33:13 by avaliull          #+#    #+#             */
/*   Updated: 2025/01/04 14:37:42 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include "libft_printf/ft_printf.h"

typedef struct	s_intlist
{
	int		element;
	struct s_intlist		*next;
}			t_intlist;

typedef struct	s_stacks
{
	t_intlist		*a;
	t_intlist		*b;
	int		a_len;
	int		b_len;
}			t_stacks;

/* list functions */
void	fill_stack(t_intlist *a, int count, char **numbers);
t_stacks	*allocate_stacks(int count);
void	free_all(t_stacks *stacks);
void	switch_elements(t_intlist *node1, t_intlist *node2);

#endif
