/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerrors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:09:25 by gribeiro          #+#    #+#             */
/*   Updated: 2025/02/05 21:57:30 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_checkduplicates (char **list);

int	ft_checkerrors(char **list)
{
	int		i;
	int		n;

	i = 0;
	while (list[i])
	{
        n = 0;
        if (list[i][n] == '-' || list[i][n] == '+')
            n++;
        if (list[i][n] == '\0')
            return (1);
        while (list[i][n])
        {
            if (ft_isdigit (list[i][n]) == 0)
                return (1);
            n++;
        }
        if (ft_atol (list[i]) > INT_MAX || ft_atol (list[i]) < INT_MIN)
            return (1);
        i++;
    }
    if (ft_checkduplicates (list))
        return (1);
    return (0);
}

static int ft_checkduplicates (char **list)
{
    int     i;
    int     n;

    i = 0;
    while (list[i])
    {
        n = 0;
        while (list[n])
        {
            if (n != i && (atol (list[i]) == atol (list[n])))
                return (1);
            n++;
        }
        i++;
    }
    return (0);
}

int		sorted(t_node *st_a)
{
	int		i;

	i = fstelm (st_a) + 1;
	while (st_a[i].idx != -1)
	{
		if (st_a[i].nbr < st_a[i - 1].nbr && st_a[i].filled == 1
                && st_a[i - 1].filled == 1)
			return (0);
		i++;
	}
	return (1);
}