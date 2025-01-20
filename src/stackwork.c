/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackwork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:09:43 by gribeiro          #+#    #+#             */
/*   Updated: 2025/01/16 21:46:02 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		calc_btarget(t_node *st_a, t_node *st_b, int target_a)
{
	int		i;
	int		target_b;

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

static int	mv_same_dir (t_node *st_a, t_node *st_b, int target_a, int target_b)
{
	int mdn_a;
	int mdn_b;

	mdn_a = ((st_a[lstelm(st_a)].idx-st_a[fstelm(st_a)].idx)/2)+fstelm(st_a);
	mdn_b = ((st_b[lstelm(st_b)].idx-st_b[fstelm(st_b)].idx)/2)+fstelm(st_b);
	if (((st_a[target_a].idx <= st_a[mdn_a].idx 
			&& st_b[target_b].idx <= st_b[mdn_b].idx)
			|| (st_a[target_a].idx > st_a[mdn_a].idx
			&& st_b[target_b].idx > st_b[mdn_b].idx)) 
			&& st_a[target_a].idx != st_a[fstelm (st_a)].idx)
		return (1);
	return (0);
}

int		cost(t_node *st_a, t_node *st_b, int target_a, int target_b)
{
	int		mdn_a;
	int		mdn_b;
	int		mov_a;
	int		mov_b;

	mdn_a = ((st_a[lstelm(st_a)].idx-st_a[fstelm(st_a)].idx)/2)+fstelm(st_a);
	mdn_b = ((st_b[lstelm(st_b)].idx-st_b[fstelm(st_b)].idx)/2)+fstelm(st_b);
	if (st_a[target_a].idx <= st_a[mdn_a].idx)
		mov_a = st_a[target_a].idx - st_a[fstelm (st_a)].idx;
	if (st_a[target_a].idx > st_a[mdn_a].idx)
		mov_a = (st_a[lstelm (st_a)].idx - st_a[target_a].idx) + 1;
	mov_a++;
	if (emptystack (st_b))
		return (mov_a);
	if (st_b[target_b].idx <= st_b[mdn_b].idx)
		mov_b = st_b[target_b].idx - st_b[fstelm (st_b)].idx;
	if (st_b[target_b].idx > st_b[mdn_b].idx)
		mov_b = (st_b[lstelm (st_b)].idx - st_b[target_b].idx) + 1;
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
	int		mdn_a;
	int		mdn_b;
	int		trgnum_a;
	int		trgnum_b;
	
	trgnum_a = st_a[min_a].nbr;
	trgnum_b = st_b[target_b].nbr;
	mdn_a = ((st_a[lstelm(st_a)].idx-st_a[fstelm(st_a)].idx)/2)+fstelm(st_a);
	mdn_b = ((st_b[lstelm(st_b)].idx-st_b[fstelm(st_b)].idx)/2)+fstelm(st_b);
	if ((st_a[min_a].idx <= st_a[mdn_a].idx
			&& st_b[target_b].idx <= st_b[mdn_b].idx) 
			&& (st_a[min_a].nbr != st_a[fstelm (st_a)].nbr) 
			&& (st_b[target_b].nbr != st_b[fstelm (st_b)].nbr))
		while (st_a[fstelm (st_a)].nbr != trgnum_a && st_b[fstelm (st_b)].nbr != trgnum_b)
				rr (st_a, st_b);
	if ((st_a[min_a].idx > st_a[mdn_a].idx
			&& st_b[target_b].idx > st_b[mdn_b].idx)
			&& (st_a[min_a].nbr != st_a[fstelm (st_a)].nbr) 
			&& (st_b[target_b].nbr != st_b[fstelm (st_b)].nbr))
		while (st_a[fstelm (st_a)].nbr != trgnum_a && st_b[fstelm (st_b)].nbr != trgnum_b)
				rrr (st_a, st_b);	
}

void	push_element(t_node *st_a, t_node *st_b, int min_a, int target_b)
{
	int		mdn_a;
	int		mdn_b;
	int		trgnum_a;
	int		trgnum_b;
	
	trgnum_a = st_a[min_a].nbr;
	trgnum_b = st_b[target_b].nbr;
	mdn_a = ((st_a[lstelm(st_a)].idx-st_a[fstelm(st_a)].idx)/2)+fstelm(st_a);
	mdn_b = ((st_b[lstelm(st_b)].idx-st_b[fstelm(st_b)].idx)/2)+fstelm(st_b);
	rr_rrr (st_a, st_b, min_a, target_b);
	if (st_a[min_a].idx <= st_a[mdn_a].idx)
		while (st_a[fstelm (st_a)].nbr != trgnum_a)
			ra (st_a);
	if (st_a[min_a].idx > st_a[mdn_a].idx)
		while (st_a[fstelm (st_a)].nbr != trgnum_a)
			rra (st_a);
	if (st_b[target_b].idx <= st_b[mdn_b].idx)
		while (st_b[fstelm (st_b)].nbr != trgnum_b)
			rb (st_b);
	if (st_b[target_b].idx > st_b[mdn_b].idx)
		while (st_b[fstelm (st_b)].nbr != trgnum_b)
			rrb (st_b);	
	if (st_a[fstelm(st_a)].nbr == trgnum_a && st_b[fstelm (st_b)].nbr == trgnum_b)
		pb (st_a, st_b);
}

int		calc_atarget (t_node *st_a, t_node *st_b, int target_b)
{
	int		i;
	int		target_a;

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

void	push_btoa(t_node *st_a, t_node *st_b, int target_a, int target_b)
{
	int		mdn_a;
	int		mdn_b;
	int		trgnum_a;
	int		trgnum_b;

	mdn_a = ((st_a[lstelm (st_a)].idx - st_a[fstelm (st_a)].idx) / 2) + fstelm (st_a);
	mdn_b = ((st_b[lstelm (st_b)].idx - st_b[fstelm (st_b)].idx) / 2) + fstelm (st_b);
	trgnum_a = st_a[target_a].nbr;
	trgnum_b = st_b[target_b].nbr;
	while (st_a[fstelm (st_a)].nbr != trgnum_a)
	{
		if (st_a[target_a].idx <= st_a[mdn_a].idx)
			ra (st_a);
		else
			rra (st_a);
	}
	while (st_b[fstelm (st_b)].nbr != trgnum_b)
	{
		if (st_b[target_b].idx <= st_b[mdn_b].idx)
			rb (st_b);
		else
			rrb (st_b);
	}	
	pa (st_a, st_b);
}

int		org_a (t_node *st_a)
{
	int		min_a;
	int		min_i;
	int		mdn_a;

	min_a = st_a[minelem (st_a)].nbr;
	min_i = st_a[minelem (st_a)].idx;
	mdn_a = ((st_a[lstelm (st_a)].idx - st_a[fstelm (st_a)].idx) / 2) + fstelm (st_a);
	if (st_a[min_i].idx <= st_a[mdn_a].idx)
	{
		while (st_a[fstelm (st_a)].nbr != min_a)
			ra (st_a);
	}
	else
		while (st_a[fstelm (st_a)].nbr != min_a)
			rra (st_a);
	return (0);
}

int		back_to_a(t_node *st_a, t_node *st_b)
{
	int		target_a;
	int		i;

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