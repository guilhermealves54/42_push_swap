/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 01:09:06 by gribeiro          #+#    #+#             */
/*   Updated: 2025/02/06 01:19:25 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	emptstk(t_node *st_a, t_node *st_b)
{
	int	i;

	i = 0;
	st_b[i].nbr = st_a[fs_e (st_a)].nbr;
	st_b[i].filled = st_a[fs_e (st_a)].filled;
	st_a[fs_e (st_a)].nbr = 0;
	st_a[fs_e (st_a)].filled = 0;
}

void	pb(t_node *st_a, t_node *st_b)
{
	int	i;

	i = 0;
	if (emptystack (st_b))
		emptstk (st_a, st_b);
	else
	{
		i = ls_e (st_b);
		while (st_b[i].idx >= st_b[fs_e (st_b)].idx)
		{
			st_b[i + 1].nbr = st_b[i].nbr;
			st_b[i + 1].filled = st_b[i].filled;
			if (i == 0)
				break ;
			i--;
		}
		i = fs_e (st_b);
		if (i > 0)
			i--;
		st_b[i].nbr = st_a[fs_e (st_a)].nbr;
		st_b[i].filled = 1;
		st_a[fs_e (st_a)].nbr = 0;
		st_a[fs_e (st_a)].filled = 0;
	}
	write(1, "pb\n", 3);
}

void	pa(t_node *st_a, t_node *st_b)
{
	int	i;

	i = 0;
	push_up (st_a);
	i = ls_e (st_a);
	while (st_a[i].idx >= st_a[fs_e (st_a)].idx)
	{
		st_a[i + 1].nbr = st_a[i].nbr;
		st_a[i + 1].filled = st_a[i].filled;
		if (i == 0)
			break ;
		i--;
	}
	i = 0;
	st_a[i].filled = 1;
	st_a[0].nbr = st_b[fs_e (st_b)].nbr;
	st_b[fs_e (st_b)].nbr = 0;
	st_b[fs_e (st_b)].filled = 0;
	write(1, "pa\n", 3);
}

void	push_up(t_node *st)
{
	int	a;
	int	i;

	a = fs_e (st);
	i = 0;
	if (st[i].filled == 0)
	{
		while (st[a].idx != -1)
		{
			st[i].nbr = st[a].nbr;
			st[i].filled = st[a].filled;
			st[a].filled = 0;
			st[a].nbr = 0;
			a++;
			i++;
		}
	}
}

void	rrr(t_node *st_a, t_node *st_b)
{
	int	temp;
	int	i;
	int	min;

	min = fs_e (st_a);
	i = ls_e (st_a);
	temp = st_a[i].nbr;
	while (i > min)
	{
		st_a[i].nbr = st_a[i - 1].nbr;
		i--;
	}
	st_a[min].nbr = temp;
	min = fs_e (st_b);
	i = ls_e (st_b);
	temp = st_b[i].nbr;
	while (i > min)
	{
		st_b[i].nbr = st_b[i - 1].nbr;
		i--;
	}
	st_b[min].nbr = temp;
	write (1, "rrr\n", 4);
}
