# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 00:50:36 by gribeiro          #+#    #+#              #
#    Updated: 2025/01/15 14:51:26 by gribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	src/push_swap.c src/ft_split.c src/ft_atol.c src/ft_calloc.c src/ft_isdigit.c src/ft_atoi.c src/ft_checkerrors.c src/ft_sortstack.c src/ft_checks.c src/operations.c src/stackwork.c
OBJS	=	$(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME):
	$(OBJS)
	ar rcs ${NAME} ${OBJS}

test:
	cc $(SRC) $(CFLAGS) -o push_swap.out
	./push_swap.out 2336 -2798 -2604 -2775 841 2479 3713 4382 418 2529 -3889 1045 -1457 -742 -299 2193 -4012 -2915 693 1281 2535 -3499 -4392 4655 281 1152 -4810 2166 -2298 -1454

all:
	$(NAME)

clean:
	rm -f $(OBJS)

fclean:
	clean
	rm -f $(NAME)

re:
	fclean all