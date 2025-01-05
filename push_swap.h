/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:33:13 by avaliull          #+#    #+#             */
/*   Updated: 2025/01/05 19:31:17 by avaliull       ########   odam.nl        */
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
	int		len_a;
	int		len_b;
}			t_stacks;

/* list functions */
void	fill_stack(t_intlist *a, int count, char **numbers);
t_stacks	*allocate_stacks(int count);
t_intlist *get_element_n(t_intlist *node, int n);
void	free_exit(t_stacks *stacks, int error_check);
void	switch_elements(t_intlist *prev, t_intlist *node1, t_intlist *node2);
/* actions */
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

#endif
