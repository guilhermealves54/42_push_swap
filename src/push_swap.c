/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 00:50:30 by gribeiro          #+#    #+#             */
/*   Updated: 2025/01/09 15:05:53 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		**filllist(char **argv, int argc, int freeflag);
static int		checkerrors(char **argv, int argc);
static t_node	*fillstack(int argc, char **argv, t_node *stack_a, t_node *stack_b);
static void		freemem(char **list, t_node *stack_a, t_node *stack_b, int freeflag);

int		main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**list;
	int		freeflag;
	
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	argv++;
	list = argv;
	if (argc == 2)
		list = filllist (argv, &argc, &freeflag);
	if (checkerrors (list, argc) != 0)
	{
		free (list);
		return (write (1, "Error", 5), 1);
	}


	freemem (list, stack_a, stack_b, freeflag);
	return (0);
}

static char	**filllist(char **argv, int argc, int freeflag)
{
	char	**list;

	list = ft_split (argv[1], ' ');
	argc = 0;
	while (list[argc])
		argc++;
	argc += 1;
	freeflag = 1;
	return (list);
}

static int	checkerrors(char **argv, int argc)
{
	return (0);
}

static t_node	*fillstack(int argc, char **list, t_node *stack_a, t_node *stack_b)
{
	stack_a = ft_calloc (argc, sizeof(t_node));
	if (stack_a == NULL)
		return (NULL);
	stack_b = ft_calloc (argc, sizeof(t_node));
	if (stack_b == NULL)
		return (NULL);

	return (stack_a);
}

static void freemem (char **list, t_node *stack_a, t_node *stack_b, int freeflag)
{
	
}