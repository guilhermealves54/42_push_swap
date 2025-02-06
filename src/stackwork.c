/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackwork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:09:43 by gribeiro          #+#    #+#             */
/*   Updated: 2025/02/06 01:29:53 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_btarget(t_node *st_a, t_node *st_b, int target_a)
{
	int	i;
	int	target_b;

	if (emptystack (st_b) == 1)
		return (0);
	if (st_a[target_a].nbr > st_b[maxelem (st_b)].nbr)
		return (maxelem (st_b));
	else if (st_a[target_a].nbr < st_b[minelem (st_b)].nbr)
		return (maxelem(st_b));
	i = 0;
	target_b = minelem(st_b);
	while (st_b[i].idx != -1)
	{
		if (st_b[i].filled == 1)
		{
			if ((st_b[i].nbr < st_a[target_a].nbr
					&& st_b[i].nbr > st_b[target_b].nbr))
				target_b = i;
		}
		i++;
	}
	return (target_b);
}

static int	mv_same_dir(t_node *st_a, t_node *st_b, int target_a, int target_b)
{
	int	mdn_a;
	int	mdn_b;

	mdn_a = ((st_a[ls_e(st_a)].idx - st_a[fs_e(st_a)].idx) / 2) + fs_e(st_a);
	mdn_b = ((st_b[ls_e(st_b)].idx - st_b[fs_e(st_b)].idx) / 2) + fs_e(st_b);
	if (((st_a[target_a].idx <= st_a[mdn_a].idx
				&& st_b[target_b].idx <= st_b[mdn_b].idx)
			|| (st_a[target_a].idx > st_a[mdn_a].idx
				&& st_b[target_b].idx > st_b[mdn_b].idx))
		&& st_a[target_a].idx != st_a[fs_e (st_a)].idx)
		return (1);
	return (0);
}

int	cost(t_node *st_a, t_node *st_b, int target_a, int target_b)
{
	int	mdn_a;
	int	mdn_b;
	int	mov_a;
	int	mov_b;

	mdn_a = ((st_a[ls_e(st_a)].idx - st_a[fs_e(st_a)].idx) / 2) + fs_e(st_a);
	mdn_b = ((st_b[ls_e(st_b)].idx - st_b[fs_e(st_b)].idx) / 2) + fs_e(st_b);
	if (st_a[target_a].idx <= st_a[mdn_a].idx)
		mov_a = st_a[target_a].idx - st_a[fs_e (st_a)].idx;
	if (st_a[target_a].idx > st_a[mdn_a].idx)
		mov_a = (st_a[ls_e (st_a)].idx - st_a[target_a].idx) + 1;
	mov_a++;
	if (emptystack (st_b))
		return (mov_a);
	if (st_b[target_b].idx <= st_b[mdn_b].idx)
		mov_b = st_b[target_b].idx - st_b[fs_e (st_b)].idx;
	if (st_b[target_b].idx > st_b[mdn_b].idx)
		mov_b = (st_b[ls_e (st_b)].idx - st_b[target_b].idx) + 1;
	if (mv_same_dir (st_a, st_b, target_a, target_b))
	{
		if (mov_a > mov_b)
			return (mov_a + 1);
		return (mov_b + 1);
	}
	return (mov_a + mov_b);
}

void	rr_rrr(t_node *st_a, t_node *st_b, int min_a, int target_b)
{
	int	mdn_a;
	int	mdn_b;
	int	trn_a;
	int	trn_b;

	trn_a = st_a[min_a].nbr;
	trn_b = st_b[target_b].nbr;
	mdn_a = ((st_a[ls_e(st_a)].idx - st_a[fs_e(st_a)].idx) / 2) + fs_e(st_a);
	mdn_b = ((st_b[ls_e(st_b)].idx - st_b[fs_e(st_b)].idx) / 2) + fs_e(st_b);
	if ((st_a[min_a].idx <= st_a[mdn_a].idx
			&& st_b[target_b].idx <= st_b[mdn_b].idx)
		&& (st_a[min_a].nbr != st_a[fs_e (st_a)].nbr)
		&& (st_b[target_b].nbr != st_b[fs_e (st_b)].nbr))
		while (st_a[fs_e (st_a)].nbr != trn_a && st_b[fs_e (st_b)].nbr != trn_b)
			rr (st_a, st_b);
	if ((st_a[min_a].idx > st_a[mdn_a].idx
			&& st_b[target_b].idx > st_b[mdn_b].idx)
		&& (st_a[min_a].nbr != st_a[fs_e (st_a)].nbr)
		&& (st_b[target_b].nbr != st_b[fs_e (st_b)].nbr))
		while (st_a[fs_e (st_a)].nbr != trn_a && st_b[fs_e (st_b)].nbr != trn_b)
			rrr (st_a, st_b);
}

void	push_element(t_node *st_a, t_node *st_b, int min_a, int target_b)
{
	int	mdn_a;
	int	mdn_b;
	int	trn_a;
	int	trn_b;

	trn_a = st_a[min_a].nbr;
	trn_b = st_b[target_b].nbr;
	mdn_a = ((st_a[ls_e(st_a)].idx - st_a[fs_e(st_a)].idx) / 2) + fs_e(st_a);
	mdn_b = ((st_b[ls_e(st_b)].idx - st_b[fs_e(st_b)].idx) / 2) + fs_e(st_b);
	rr_rrr (st_a, st_b, min_a, target_b);
	if (st_a[min_a].idx <= st_a[mdn_a].idx)
		while (st_a[fs_e (st_a)].nbr != trn_a)
			ra (st_a);
	if (st_a[min_a].idx > st_a[mdn_a].idx)
		while (st_a[fs_e (st_a)].nbr != trn_a)
			rra (st_a);
	if (st_b[target_b].idx <= st_b[mdn_b].idx)
		while (st_b[fs_e (st_b)].nbr != trn_b)
			rb (st_b);
	if (st_b[target_b].idx > st_b[mdn_b].idx)
		while (st_b[fs_e (st_b)].nbr != trn_b)
			rrb (st_b);
	if (st_a[fs_e(st_a)].nbr == trn_a && st_b[fs_e (st_b)].nbr == trn_b)
		pb (st_a, st_b);
}
