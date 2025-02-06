/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:09:37 by gribeiro          #+#    #+#             */
/*   Updated: 2025/02/06 01:19:25 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node *stack)
{
	int	temp;
	int	i;
	int	min;

	min = fs_e (stack);
	i = ls_e (stack);
	temp = stack[i].nbr;
	while (i > min)
	{
		stack[i].nbr = stack[i - 1].nbr;
		i--;
	}
	stack[fs_e (stack)].nbr = temp;
	write (1, "rra\n", 4);
}

void	ra(t_node *stack)
{
	int	temp;
	int	i;
	int	max;

	max = ls_e (stack);
	i = fs_e (stack);
	temp = stack[i].nbr;
	while (i < max)
	{
		stack[i].nbr = stack[i + 1].nbr;
		i++;
	}
	stack[max].nbr = temp;
	write (1, "ra\n", 3);
}

void	rrb(t_node *stack)
{
	int	temp;
	int	i;
	int	min;

	min = fs_e (stack);
	i = ls_e (stack);
	temp = stack[i].nbr;
	while (i > min)
	{
		stack[i].nbr = stack[i - 1].nbr;
		i--;
	}
	stack[min].nbr = temp;
	write (1, "rrb\n", 4);
}

void	rb(t_node *stack)
{
	int	temp;
	int	i;
	int	max;

	max = ls_e (stack);
	i = fs_e (stack);
	temp = stack[i].nbr;
	while (i < max)
	{
		stack[i].nbr = stack[i + 1].nbr;
		i++;
	}
	stack[max].nbr = temp;
	write (1, "rb\n", 3);
}

void	rr(t_node *st_a, t_node *st_b)
{
	int	temp;
	int	i;
	int	max;

	max = ls_e (st_a);
	i = fs_e (st_a);
	temp = st_a[i].nbr;
	while (i < max)
	{
		st_a[i].nbr = st_a[i + 1].nbr;
		i++;
	}
	st_a[max].nbr = temp;
	max = ls_e (st_b);
	i = fs_e (st_b);
	temp = st_b[i].nbr;
	while (i < max)
	{
		st_b[i].nbr = st_b[i + 1].nbr;
		i++;
	}
	st_b[max].nbr = temp;
	write (1, "rr\n", 3);
}
