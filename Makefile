# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                            :+:    :+:            #
#                                                     +:+ +:+         +:+      #
#    By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 12:39:24 by avaliull          #+#    #+#              #
#    Updated: 2024/12/17 13:47:55 by avaliull       ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

CFILES	=	push_swap.c

OFILES	= $(CFILES:.c=.o)

LIBFT_PRINTF	= libft_printf/libftprintf.a

LIBFT_PRINTF_DIR = libft_printf

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

AR	= ar -rcs

NAME	= push_swap.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT_PRINTF):	
	$(MAKE) all -C $(LIBFT_PRINTF_DIR)

$(NAME): $(OFILES) $(LIBFT_PRINTF)
	cp $(LIBFT_PRINTF) $(NAME)
	$(AR) $(NAME) $(OFILES)

libft_printf_clean:
	$(MAKE) clean -C $(LIBFT_PRINTF_DIR)

# this is for bonus
# bonus: all

clean: libft_printf_clean
	$(RM) $(OFILES)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re libft_printf_clean
