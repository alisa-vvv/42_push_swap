/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:33:13 by avaliull          #+#    #+#             */
/*   Updated: 2024/12/24 12:25:24 by avaliull       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_list
{
	int		element;
	s_stack		*next;
}			t_list;

struct	s_stacks
{
	s_stack		*a;
	s_stack		*b;
	int		a_len;
	int		b_len;
};

# include <stddef.h>
# include <unistd.h>
# include "libft_printf/ft_printf.h"

#endif
