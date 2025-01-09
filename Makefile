# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 00:50:36 by gribeiro          #+#    #+#              #
#    Updated: 2025/01/09 18:14:07 by gribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= src/push_swap.c src/ft_split.c src/ft_atol.c src/ft_calloc.c src/ft_isdigit.c src/ft_checkerrors.c
OBJS	= $(SRCS:.c=.o)

CC = cc



test:
	cc $(SRC) $(CFLAGS) -o push_swap.out -g
	./push_swap.out 10 20 24324