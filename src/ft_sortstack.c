/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:09:16 by gribeiro          #+#    #+#             */
/*   Updated: 2025/02/05 16:03:17 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort3(t_node *stack)
{
	while (!sorted (stack))
	{
		if (stack[fstelm (stack)].nbr == stack[maxelem (stack)].nbr)
			ra (stack);
		else if (stack[lstelm (stack)].nbr == stack[maxelem (stack)].nbr)
			sa (stack);
		else
			rra (stack);
	}
}

static void	a_to_b(t_node *st_a, t_node *st_b, int *min_a, int *min_b)
{
	int		i;
	int		mn_cst;
	int		target_b;

	while (stacksize(st_a) > 3)
	{
		i = fstelm (st_a);
		mn_cst = cost (st_a, st_b, i, calc_btarget (st_a, st_b, i));
		while (st_a[i].idx != -1)
		{
			target_b = calc_btarget (st_a, st_b, i);
			if (st_a[i].filled == 1)
			{
				target_b = calc_btarget (st_a, st_b, i);
				if (cost (st_a, st_b, i, target_b) <= mn_cst)
				{
					mn_cst = cost (st_a, st_b, i, target_b);
					*min_a = i;
					*min_b = target_b;
				}
			}
			i++;
		}
		push_element (st_a, st_b, *min_a, *min_b);
	}
}

static int	biggersort(t_node *st_a, t_node *st_b)
{
	int		min_a;
	int		min_b;

	if (stacksize(st_a) == 4)
	{
		pb (st_a, st_b);
		sort3 (st_a);
		return (back_to_a (st_a, st_b));
	}
	pb (st_a, st_b);
	pb (st_a, st_b);
	a_to_b (st_a, st_b, &min_a, &min_b);
	sort3 (st_a);
	return (back_to_a (st_a, st_b));
}

int	sortstack(t_node *st_a, t_node *st_b, int argc)
{
	if (argc == 3)
		return (sa (st_a), 0);
	if (argc == 4)
		return (sort3 (st_a), 0);
	else
		return (biggersort (st_a, st_b));
	return (0);
}
