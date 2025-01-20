/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:09:30 by gribeiro          #+#    #+#             */
/*   Updated: 2025/01/15 22:24:23 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		fstelm (t_node *stack)
{
	int 	i;

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

int		lstelm (t_node *stack)
{
	int 	i;

	i = 0;
	while (stack[i].idx != -1)
		i++;
	while (stack[i].filled != 1 && i >= 0)
		i--;
	return (i);
}

int		minelem (t_node *stack)
{
	int 	i;
	int		min;
	int		minindex;

	i = fstelm (stack);
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

int		maxelem (t_node *stack)
{
	int 	i;
	int		max;
	int		maxindex;

	i = fstelm (stack);
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

int		emptystack (t_node *stack)
{
	int i;

	i = 0;
	while (stack[i].idx != -1)
	{
		if (stack[i].filled == 1)
			return (0);
		i++;
	}
	return (1);
}

int		stacksize(t_node *st_a)
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