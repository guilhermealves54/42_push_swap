# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 00:50:36 by gribeiro          #+#    #+#              #
#    Updated: 2025/02/06 01:41:24 by gribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC	= $(addprefix src/, push_swap.c ft_split.c ft_libfuncs.c ft_checkerrors.c ft_sortstack.c ft_checks.c ops.c stackwork.c stackwork2.c ops2.c)
OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

test: $(NAME)
	./push_swap 2336 -2798 -2604 -2775 10 5 3 1

valgrind: $(NAME)
	valgrind ./push_swap "2336 -2798 -2604 -2775 10 5 3 1"

error: $(NAME)
	./push_swap 9 6 9 3
	./push_swap 10b 7 3 4
	./push_swap -+3 2 1 6

checker: $(NAME)
	@if [ ! -f checker_linux ]; then \
		echo "Downloading checker_linux..."; \
		curl -o checker_linux https://cdn.intra.42.fr/document/document/28341/checker_linux; \
		chmod 777 checker_linux; \
	fi
	ARG="4 10 1 3 2"; ./push_swap $$ARG | ./checker_linux $$ARG
	ARG="2336 -2798 -2604 -2775 10 5 3 1"; ./push_swap $$ARG | ./checker_linux $$ARG

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	