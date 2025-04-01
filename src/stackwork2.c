/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackwork2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 01:20:08 by gribeiro          #+#    #+#             */
/*   Updated: 2025/04/01 18:17:34 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	back_to_a(t_node *st_a, t_node *st_b)
{
	int	target_a;
	int	i;

	i = 0;
	while (st_b[i].idx != -1)
	{
		if (st_b[i].filled == 1)
		{
			target_a = calc_atarget (st_a, st_b, i);
			push_btoa (st_a, st_b, target_a, i);
		}
		i++;
	}
	org_a (st_a);
	return (0);
}

void	push_btoa(t_node *st_a, t_node *st_b, int target_a, int target_b)
{
	int	mdn_a;
	int	mdn_b;
	int	trn_a;
	int	trn_b;

	mdn_a = ((st_a[ls_e (st_a)].idx - st_a[fs_e (st_a)].idx) / 2) + fs_e (st_a);
	mdn_b = ((st_b[ls_e (st_b)].idx - st_b[fs_e (st_b)].idx) / 2) + fs_e (st_b);
	trn_a = st_a[target_a].nbr;
	trn_b = st_b[target_b].nbr;
	while (st_a[fs_e (st_a)].nbr != trn_a)
	{
		if (st_a[target_a].idx <= st_a[mdn_a].idx)
			ra (st_a);
		else
			rra (st_a);
	}
	while (st_b[fs_e (st_b)].nbr != trn_b)
	{
		if (st_b[target_b].idx <= st_b[mdn_b].idx)
			rb (st_b);
		else
			rrb (st_b);
	}
	pa (st_a, st_b);
}

int	org_a(t_node *st_a)
{
	int	min_a;
	int	min_i;
	int	mdn_a;

	min_a = st_a[minelem (st_a)].nbr;
	min_i = st_a[minelem (st_a)].idx;
	mdn_a = ((st_a[ls_e (st_a)].idx - st_a[fs_e (st_a)].idx) / 2) + fs_e (st_a);
	if (st_a[min_i].idx <= st_a[mdn_a].idx)
	{
		while (st_a[fs_e (st_a)].nbr != min_a)
			ra (st_a);
	}
	else
		while (st_a[fs_e (st_a)].nbr != min_a)
			rra (st_a);
	return (0);
}

int	calc_atarget(t_node *st_a, t_node *st_b, int target_b)
{
	int	i;
	int	target_a;

	if (st_b[target_b].nbr > st_a[maxelem (st_a)].nbr)
		return (minelem (st_a));
	else if (st_b[target_b].nbr < st_a[minelem (st_a)].nbr)
		return (minelem(st_a));
	i = 0;
	target_a = maxelem(st_a);
	while (st_a[i].idx != -1)
	{
		if (st_a[i].filled == 1)
		{
			if ((st_a[i].nbr > st_b[target_b].nbr
					&& st_a[i].nbr < st_a[target_a].nbr))
				target_a = i;
		}
		i++;
	}
	return (target_a);
}

int	emptystack(t_node *stack)
{
	int	i;

	i = 0;
	while (stack[i].idx != -1)
	{
		if (stack[i].filled == 1)
			return (0);
		i++;
	}
	return (1);
}
