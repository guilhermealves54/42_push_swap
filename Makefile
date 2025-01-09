# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 00:50:36 by gribeiro          #+#    #+#              #
#    Updated: 2025/01/09 02:04:08 by gribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= src/push_swap.c
OBJS	= $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror



test:
	cc $(SRC) $(CFLAGS) -o push_swap.out
	./push_swap.out "10 20 30"