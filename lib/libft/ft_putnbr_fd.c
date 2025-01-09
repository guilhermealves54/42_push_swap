/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:52 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/13 14:33:55 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;

	nl = n;
	if (nl < 0)
	{
		ft_putchar_fd ('-', fd);
		nl *= -1;
	}
	if (nl >= 0 && nl < 10)
	{
		ft_putchar_fd (nl + 48, fd);
	}
	if (nl >= 10)
	{
		ft_putnbr_fd(nl / 10, fd);
		ft_putchar_fd ((nl % 10) + 48, fd);
	}
}
/*
#include<stdio.h>
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
}*/
