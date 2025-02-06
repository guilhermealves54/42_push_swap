/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 00:50:30 by gribeiro          #+#    #+#             */
/*   Updated: 2025/02/06 18:07:43 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		**filllist(char **argv, int *argc, int *freeflag);
static t_node	*fillstack(int argc, char **list, int empty);
static void		freemem(char **list, t_node *st_a, t_node *st_b, int freeflag);

int	main(int argc, char **argv)
{
	t_node	*st_a;
	t_node	*st_b;
	char	**list;
	int		freeflag;

	freeflag = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (write (2, "Error\n", 6), 1);
	argv++;
	list = argv;
	if (argc == 2)
		list = filllist (argv, &argc, &freeflag);
	if (ft_checkerrors (list))
	{
		if (freeflag)
			free (list);
		return (write (2, "Error\n", 6), 1);
	}
	st_a = fillstack (argc, list, 0);
	st_b = fillstack (argc, list, 1);
	if (st_a == NULL || st_b == NULL)
		return (1);
	if (!sorted (st_a))
		sortstack (st_a, st_b, argc);
	freemem (list, st_a, st_b, freeflag);
}

static char	**filllist(char **argv, int *argc, int *freeflag)
{
	char	**list;
	int		i;

	list = ft_split (argv[0], ' ');
	i = 0;
	while (list[i])
		i++;
	*argc = i + 1;
	*freeflag = 1;
	return (list);
}

static t_node	*fillstack(int argc, char **list, int empty)
{
	t_node	*stack;
	int		i;

	stack = ft_calloc (argc, sizeof(t_node));
	if (stack == NULL)
		return (NULL);
	i = 0;
	while (i < (argc - 1))
	{
		if (!empty)
		{
			stack[i].nbr = ft_atoi (list[i]);
			stack[i].filled = 1;
		}
		else
		{
			stack[i].nbr = 0;
			stack[i].filled = 0;
		}
		stack[i].idx = i;
		i++;
	}
	stack[i].idx = -1;
	return (stack);
}

static void	freemem(char **list, t_node *st_a, t_node *st_b, int freeflag)
{
	int		i;

	i = 0;
	if (freeflag)
	{
		while (list[i])
		{
			free(list[i++]);
		}
		free (list);
	}
	free (st_a);
	free (st_b);
}
