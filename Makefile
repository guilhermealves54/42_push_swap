# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 00:50:36 by gribeiro          #+#    #+#              #
#    Updated: 2025/01/10 03:20:05 by gribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= src/push_swap.c src/ft_split.c src/ft_atol.c src/ft_calloc.c src/ft_isdigit.c src/ft_checkerrors.c src/ft_atoi.c src/ft_sortstack.c src/ft_checks.c src/operations.c
OBJS	= $(SRCS:.c=.o)

CC = cc
# CFLAGS = -Wall -Wextra -Werror

test:
	cc $(SRC) $(CFLAGS) -o push_swap.out -g
	./push_swap.out "3 1 2 4 5"