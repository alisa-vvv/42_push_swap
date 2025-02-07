# **************************************************************************** # #
#                                                         :::      ::::::::    #
#    Makefile                                            :+:    :+:            #
#                                                     +:+ +:+         +:+      #
#    By: avaliull <avaliull@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 12:39:24 by avaliull          #+#    #+#              #
#    Updated: 2025/01/07 19:48:57 by avaliull       ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

CFILES	=	push_swap.c\
			median_of_medians.c\
			sorting.c\
			opcount_wrappers.c\
			rotation_counting.c\
			combination_counting.c\
			candidate_b_to_a.c\
			candidate_find_b_to_a.c\
			candidate_a_to_b.c\
			candidate_find_a_to_b.c\
			three_or_less.c\
			lis.c\
			list_funcs.c\
			list_wrappers.c\
			init.c\
			exit.c\
			test_funcs.c\
			swaps.c\
			pushes.c\
			rotates.c\
			reverse_rotates.c

OBJDIR = obj

SRCDIR = src

SRCDIRS = $(addprefix $(SRCDIR)/, sorting sorting/b_to_a sorting/a_to_b\
		  list_ops init_exit operations) $(SRCDIR)

OFILES	= $(addprefix $(OBJDIR)/,$(CFILES:.c=.o))

VPATH	= $(INCLUDE) $(SRCDIRS)

LIBFT_PRINTF	= $(SRCDIR)/libft_printf/libftprintf.a

LIBFT_PRINTF_DIR = $(SRCDIR)/libft_printf

INCLUDEFILES = push_swap.h

#INCLUDE = inc $(dir $(LIBFT_PRINTF))
INCLUDE = inc $(LIBFT_PRINTF_DIR)

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

NAME	= push_swap

INPUT	= `cat input.txt`

MAKEFLAGS	= -s
#INPUT	= 1 5 3 4 9 6

$(OBJDIR):
	mkdir $@

$(OBJDIR)/%.o: %.c $(INCLUDEFILES) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(addprefix -I,$(INCLUDE))

all: $(NAME)

$(LIBFT_PRINTF):
	export CFLAGS
	$(MAKE) all -C $(LIBFT_PRINTF_DIR)

$(NAME): $(OFILES) $(LIBFT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(addprefix -I,$(INCLUDE))

libs_clean:
	$(MAKE) clean -C $(LIBFT_PRINTF_DIR)

# this is for bonus
# bonus: all

clean: libs_clean
	$(RM) $(OFILES)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

debug: CFLAGS += -g
debug: re

gdb: debug
	gdb ./$(NAME)

test:	$(NAME)
	./$< $(INPUT)

leak:	debug
	valgrind -s --leak-check=full ./$(NAME) $(INPUT)

clangd:
	$(MAKE) fclean
	intercept-build-14 make all

input:
	sh gen_testset.sh

run:
	./push_swap $(INPUT)

multitest:
	sh multitest.sh

check: $(NAME)
	./$< $(INPUT) | ./checker_linux $(INPUT)

.PHONY:	all clean fclean re libs_clean test leak debug gdb check run
