/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 00:50:30 by gribeiro          #+#    #+#             */
/*   Updated: 2025/01/09 19:10:42 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		**filllist(char **argv, int *argc, int *freeflag);
static t_node	*fillstack(int argc, char **list, int empty);
static void		freemem(char **list, t_node *stack_a, t_node *stack_b, int freeflag);

int		main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**list;
	int		freeflag;
	int		i = 0; // apagar

	freeflag = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (write (1, "Error\n", 6), 1);;
	argv++;
	list = argv;
	if (argc == 2)
		list = filllist (argv, &argc, &freeflag);
	if (ft_checkerrors (list, argc))
	{
		if (freeflag)
			free (list);
		return (write (1, "Error\n", 6), 1);
	}
	stack_a = fillstack (argc, list, 0);
	stack_b = fillstack (argc, list, 1);
	while (stack_a[i].index >= 0)
		printf ("%i 	-	%i\n", stack_a[i].index, stack_a[i++].nbr);
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
		stack[i].index = i;
		i++;
	} 
	stack[i + 1].index = -1;
	return (stack);
}

static void freemem (char **list, t_node *stack_a, t_node *stack_b, int freeflag)
{
	
}
