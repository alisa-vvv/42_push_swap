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
		sorting/median_of_medians.c\
		sorting/sorting.c\
		sorting/three_or_less.c\
		list_ops/list_funcs.c\
		list_ops/list_wrappers.c\
		init_exit/init.c\
		init_exit/exit.c\
		test_funcs.c\
		operations/swaps.c\
		operations/pushes.c\
		operations/rotates.c\
		operations/reverse_rotates.c

OFILES	= $(CFILES:.c=.o)

LIBFT_PRINTF	= libft_printf/libftprintf.a

LIBFT_PRINTF_DIR = libft_printf

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

AR	= ar -rcs

NAME	= push_swap.a

#INPUT	= 237 6 375 110 318 332 389 121 474 325 25 424 7 497 49 377 493 320 182 258 335 321 259 495 400 144 88 59 224 480 203 361 409 349 137 161 201 174 260 172 490 472 317 8 348 117 463 101 1 366 473 185 447 197 458 38 491 285 294 364 207 265 427 9 404 392 327 21 133 10 188 500 99 204 486 198 238 334 102 357 359 34 173 87 351 393 80 127 471 446 405 295 136 307 31 28 26 360 394 33 494 29 134 483 24 190 128 183 145 284 299 453 16 5 324 23 239 120 35 431 460 271 55 438 429 445 242 499 138 492 76 168 245 73 155 126 69 44 32 456 96 221 112 94 103 380 139 206 322 56 218 419 122 130 74 75 305 36 323 355 146 304 406 478 418 86 280 222 65 68 434 457 193 256 411 53 93 196 234 273 440 298 84 416 358 272 163 421 344 45 114 270 475 79 287 383 289 12 413 113 481 230 37 496 459 57 278 255 19 14 171 386 40 223 250 275 160 211 333 462 219 264 142 266 385 398 48 311 30 319 150 331 225 261 292 17 213 231 451 251 378 403 466 290 435 236 247 420 148 179 342 97 4 140 159 444 214 60 482 233 132 267 90 200 286 202 346 279 246 67 467 430 166 433 312 217 83 297 362 175 111 153 252 119 180 401 339 244 141 282 498 454 15 470 432 277 149 338 89 291 262 191 309 452 388 232 300 390 51 170 442 347 443 296 152 125 399 397 257 118 254 210 39 11 62 412 425 384 395 422 164 448 63 124 489 177 415 158 0 178 313 77 329 283 22 147 116 248 308 487 100 195 365 468 363 450 240 199 46 396 268 387 352 306 189 274 181 476 212 330 371 226 408 368 85 18 2 436 461 92 106 303 156 131 485 167 315 13 186 455 326 402 477 108 353 407 107 269 184 169 314 301 391 27 253 47 104 42 95 249 370 276 441 235 129 354 157 423 374 228 154 382 115 109 165 414 205 381 151 41 345 98 227 488 187 449 66 437 465 372 379 243 78 302 91 20 54 58 229 281 64 484 373 316 337 43 426 417 72 143 82 464 340 50 194 310 208 328 336 176 263 220 123 376 192 162 81 293 350 356 288 216 135 469 439 71 428 367 341 3 105 410 241 343 70 209 215 369 61 479

INPUT	= 1 3 2 9 6 8 10 5 7

#INPUT	= 1 3 2 6 8 5 7

#INPUT	= 1 3 2

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT_PRINTF):
	export CFLAGS
	$(MAKE) all -C $(LIBFT_PRINTF_DIR)

$(NAME): $(OFILES) $(LIBFT_PRINTF)
	cp $(LIBFT_PRINTF) $(NAME)
	$(AR) $(NAME) $(OFILES)

libs_clean:
	$(MAKE) clean -C $(LIBFT_PRINTF_DIR)

# this is for bonus
# bonus: all

clean: libs_clean
	$(RM) $(OFILES)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test:	all
	$(CC) $(CFLAGS) $(NAME) ; ./a.out $(INPUT)
check:	all
	$(CC) $(CFLAGS) $(NAME) ; ./a.out $(INPUT) | ./checker_linux $(INPUT)

leak:	all
	$(CC) $(CFLAGS) $(NAME) ; valgrind -s --leak-check=full ./a.out $(INPUT)

.PHONY:	all clean fclean re libs_clean test leak check
