/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:09:30 by gribeiro          #+#    #+#             */
/*   Updated: 2025/02/06 01:19:25 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fs_e(t_node *stack)
{
	int	i;

	i = 0;
	while (stack[i].idx != -1)
	{
		if (stack[i].filled == 1)
			return (i);
		i++;
	}
	if (stack[i].idx == -1)
		i = 0;
	return (i);
}

int	ls_e(t_node *stack)
{
	int	i;

	i = 0;
	while (stack[i].idx != -1)
		i++;
	while (stack[i].filled != 1 && i >= 0)
		i--;
	return (i);
}

int	minelem(t_node *stack)
{
	int	i;
	int	min;
	int	minindex;

	i = fs_e (stack);
	min = stack[i].nbr;
	minindex = i;
	while (stack[i].idx != -1)
	{
		if (stack[i].nbr < min && stack[i].filled == 1)
		{
			min = stack[i].nbr;
			minindex = i;
		}
		i++;
	}
	return (minindex);
}

int	maxelem(t_node *stack)
{
	int	i;
	int	max;
	int	maxindex;

	i = fs_e (stack);
	max = stack[i].nbr;
	maxindex = i;
	while (stack[i].idx != -1)
	{
		if (stack[i].nbr > max && stack[i].filled == 1)
		{
			max = stack[i].nbr;
			maxindex = i;
		}
		i++;
	}
	return (maxindex);
}

int	stacksize(t_node *st_a)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (st_a[i].idx != -1)
	{
		if (st_a[i].filled == 1)
			res++;
		i++;
	}
	return (res);
}
