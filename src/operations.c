/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:09:37 by gribeiro          #+#    #+#             */
/*   Updated: 2025/01/16 22:01:08 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *stack)
{
	int 	temp;
	int		i;

	i = fstelm (stack);
	if (stack[i + 1].filled == 1)
	{
		temp = stack[i].nbr;
		stack[i].nbr = stack[i + 1].nbr;
		stack[i + 1].nbr = temp;
		write (1, "sa\n", 3);
	}
}

void	rra(t_node *stack)
{
	int		temp;
	int 	i;
	int 	min;

	min = fstelm (stack);
	i = lstelm (stack);
	temp = stack[i].nbr;
    while (i > min)
    {
        stack[i].nbr = stack[i - 1].nbr;
        i--;
    }
    stack[fstelm (stack)].nbr = temp;
	write (1, "rra\n", 4);
}

void	ra(t_node *stack)
{
	int		temp;
	int 	i;
	int 	max;

	max = lstelm (stack);
	i = fstelm (stack);
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
	int		temp;
	int 	i;
	int 	min;

	min = fstelm (stack);
	i = lstelm (stack);
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
	int		temp;
	int 	i;
	int 	max;

	max = lstelm (stack);
	i = fstelm (stack);
	temp = stack[i].nbr;
    while (i < max)
    {
        stack[i].nbr = stack[i + 1].nbr;
        i++;
    }
    stack[max].nbr = temp;
	write (1, "rb\n", 3);
}

void	pb (t_node *st_a, t_node *st_b)
{
	int	i;

	i = 0;
	if (emptystack (st_b))
	{
		st_b[i].nbr = st_a[fstelm (st_a)].nbr;
		st_b[i].filled = st_a[fstelm (st_a)].filled;
		st_a[fstelm (st_a)].nbr = 0;
		st_a[fstelm (st_a)].filled = 0;
	}
	else
	{
		i = lstelm (st_b);
		while (st_b[i].idx >= st_b[fstelm (st_b)].idx)
		{
			st_b[i + 1].nbr = st_b[i].nbr;
			st_b[i + 1].filled = st_b[i].filled;
			i--;
		}
		i = fstelm (st_b) - 1;
		st_b[i].nbr = st_a[fstelm (st_a)].nbr;
		st_b[i].filled = 1;
		st_a[fstelm (st_a)].nbr = 0;
		st_a[fstelm (st_a)].filled = 0;
	}
	write(1, "pb\n", 3);
}

void	push_up (t_node *st)
{
	int	a;
	int	i;

	a = fstelm (st);
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

void 	pa (t_node *st_a, t_node *st_b)
{
	int	i;

	i = 0;
	push_up (st_a);
	i = lstelm (st_a);
	while (st_a[i].idx >= st_a[fstelm (st_a)].idx)
	{
		st_a[i + 1].nbr = st_a[i].nbr;
		st_a[i + 1].filled = st_a[i].filled;
		i--;
	}
	i = 0;
	st_a[i].filled = 1;
	st_a[0].nbr = st_b[fstelm (st_b)].nbr;
	st_b[fstelm (st_b)].nbr = 0;
	st_b[fstelm (st_b)].filled = 0;
	write(1, "pa\n", 3);
}

void	rr(t_node *st_a, t_node *st_b)
{
	int		temp;
	int 	i;
	int 	max;

	max = lstelm (st_a);
	i = fstelm (st_a);
	temp = st_a[i].nbr;
    while (i < max)
    {
        st_a[i].nbr = st_a[i + 1].nbr;
        i++;
    }
    st_a[max].nbr = temp;
	max = lstelm (st_b);
	i = fstelm (st_b);
	temp = st_b[i].nbr;
    while (i < max)
    {
        st_b[i].nbr = st_b[i + 1].nbr;
        i++;
    }
    st_b[max].nbr = temp;
	write (1, "rr\n", 3);
}

void	rrr(t_node *st_a, t_node *st_b)
{
	int		temp;
	int 	i;
	int 	min;

	min = fstelm (st_a);
	i = lstelm (st_a);
	temp = st_a[i].nbr;
    while (i > min)
    {
        st_a[i].nbr = st_a[i - 1].nbr;
        i--;
    }
    st_a[min].nbr = temp;
	min = fstelm (st_b);
	i = lstelm (st_b);
	temp = st_b[i].nbr;
    while (i > min)
    {
        st_b[i].nbr = st_b[i - 1].nbr;
        i--;
    }
    st_b[min].nbr = temp;
	write (1, "rrr\n", 4);
}