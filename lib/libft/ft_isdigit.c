/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:45:12 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:45:14 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
	{
		return (2048);
	}
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	c;

	printf ("Insere um número: \n");
	scanf ("%c", &c);
	printf ("Resultado ft_isdigit: %d\n", ft_isdigit(c));
	printf ("Resultado isdigit: %d\n", isdigit(c));
}*/
