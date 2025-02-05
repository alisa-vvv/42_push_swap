# **************************************************************************** #
#                                                                              #
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
			three_or_less.c\
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

SRCDIRS = $(addprefix $(SRCDIR)/, sorting list_ops init_exit operations) $(SRCDIR)

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

INPUT	= 237 6 375 110 318 332 389 121 474 325 25 424 7 497 49 377 493 320 182 258 335 321 259 495 400 144 88 59 224 480 203 361 409 349 137 161 201 174 260 172 490 472 317 8 348 117 463 101 1 366 473 185 447 197 458 38 491 285 294 364 207 265 427 9 404 392 327 21 133 10 188 500 99 204 486 198 238 334 102 357 359 34 173 87 351 393 80 127 471 446 405 295 136 307 31 28 26 360 394 33 494 29 134 483 24 190 128 183 145 284 299 453 16 5 324 23 239 120 35 431 460 271 55 438 429 445 242 499 138 492 76 168 245 73 155 126 69 44 32 456 96 221 112 94 103 380 139 206 322 56 218 419 122 130 74 75 305 36 323 355 146 304 406 478 418 86 280 222 65 68 434 457 193 256 411 53 93 196 234 273 440 298 84 416 358 272 163 421 344 45 114 270 475 79 287 383 289 12 413 113 481 230 37 496 459 57 278 255 19 14 171 386 40 223 250 275 160 211 333 462 219 264 142 266 385 398 48 311 30 319 150 331 225 261 292 17 213 231 451 251 378 403 466 290 435 236 247 420 148 179 342 97 4 140 159 444 214 60 482 233 132 267 90 200 286 202 346 279 246 67 467 430 166 433 312 217 83 297 362 175 111 153 252 119 180 401 339 244 141 282 498 454 15 470 432 277 149 338 89 291 262 191 309 452 388 232 300 390 51 170 442 347 443 296 152 125 399 397 257 118 254 210 39 11 62 412 425 384 395 422 164 448 63 124 489 177 415 158 0 178 313 77 329 283 22 147 116 248 308 487 100 195 365 468 363 450 240 199 46 396 268 387 352 306 189 274 181 476 212 330 371 226 408 368 85 18 2 436 461 92 106 303 156 131 485 167 315 13 186 455 326 402 477 108 353 407 107 269 184 169 314 301 391 27 253 47 104 42 95 249 370 276 441 235 129 354 157 423 374 228 154 382 115 109 165 414 205 381 151 41 345 98 227 488 187 449 66 437 465 372 379 243 78 302 91 20 54 58 229 281 64 484 373 316 337 43 426 417 72 143 82 464 340 50 194 310 208 328 336 176 263 220 123 376 192 162 81 293 350 356 288 216 135 469 439 71 428 367 341 3 105 410 241 343 70 209 215 369 61 479

#INPUT = 19 5 54 77 87 4 69 71 100 59 60 1 85 29 68 22 24 49 99 61 93 18 74 11 55 95 30 36 46 23 8 20 50 57 79 3 35 65 82 26 42 80 45 25 88 92 40 62 53 12 86 76 67 72 98 44 21 6 83 73 84 56 15 47 27 58 16 10 70 38 81 34 66 41 2 32 31 39 13 37 28 64 96 91 89 97 90 17 94 48 14 52 63 78 33 51 7 9 43 75

#INPUT = 491 35 332 347 708 723 958 665 494 187 113 669 326 769 445 33 533 978 137 966 687 90 59 402 701 695 945 772 503 856 863 525 306 887 547 659 749 570 781 171 921 41 69 131 660 230 176 905 703 20 907 527 918 892 498 133 762 933 57 392 329 288 979 262 58 431 580 935 120 410 732 12 47 180 621 820 350 591 652 271 397 552 103 798 296 596 386 124 2 395 387 362 492 379 318 620 910 239 178 199 442 868 45 891 692 817 957 19 453 158 893 757 916 775 514 118 965 661 864 925 205 495 575 946 423 214 403 519 208 684 926 49 190 109 579 555 238 291 511 861 578 160 858 521 768 744 785 535 99 755 84 157 117 909 31 954 448 149 369 61 464 952 81 32 822 425 360 424 235 451 825 299 603 534 34 127 883 794 615 681 566 97 293 163 890 624 678 210 313 743 359 818 323 202 300 134 650 420 10 487 172 339 429 496 846 850 328 897 722 166 771 400 558 939 135 823 865 13 598 581 605 876 985 164 310 37 250 932 728 537 295 21 200 121 219 130 564 449 486 340 457 151 839 195 951 968 994 501 374 355 733 186 758 489 303 169 349 586 56 874 694 444 319 724 913 253 507 346 249 500 599 72 686 551 316 197 356 700 811 259 418 198 680 419 801 459 405 25 231 721 816 375 980 746 44 30 577 812 251 243 366 689 826 159 838 98 529 595 477 426 107 752 975 292 320 809 672 226 833 365 484 277 467 155 380 11 1 779 421 656 148 367 568 699 388 628 714 654 753 670 62 997 468 878 93 223 972 750 761 653 331 478 707 280 417 252 209 961 147 690 358 85 763 321 536 538 474 622 736 258 55 284 600 720 931 26 574 516 635 572 493 879 787 834 895 802 630 731 790 989 476 588 502 39 119 204 778 770 844 765 854 370 441 447 949 432 836 698 618 305 96 745 102 179 673 244 315 162 261 990 651 840 683 63 485 101 737 140 751 584 829 914 606 111 539 27 414 553 314 6 860 422 217 88 766 512 517 542 608 141 609 394 947 215 224 138 24 881 7 454 89 383 337 343 760 430 704 640 569 807 203 153 211 601 443 78 125 866 282 499 896 52 181 705 308 682 940 589 999 612 275 613 638 325 247 964 185 889 729 693

#INPUT	= 6 3 2 9 1 8 10 5 12 7 4 11

#INPUT	= 1 3 2 6 8 5 7

#INPUT	= 1 4 2 5 3

#INPUT	= 6 46 12 11 38 28 34 1 33 14 24 26 42 31 40 47 21 8 48 10 3 7 19 4 25 2 9 39 44 30 29 16 20 13 15 23 41 5 43 32 37 22 36 17 27 35 50 18 45 49

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

check:	$(NAME)
	./$< $(INPUT) | ./checker_linux $(INPUT)

.PHONY:	all clean fclean re libs_clean test leak debug gdb check 
