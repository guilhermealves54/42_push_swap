/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:45:23 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:45:25 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int n)
{
	if (n >= 32 && n <= 126)
	{
		return (16384);
	}
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char	c;

	printf ("Insere um número:: \n");
	scanf ("%c", &c);
	printf ("Resultado ft_isprint: %d\n", ft_isprint(c));
	printf ("Resultado isprint: %d\n", isprint(c));
}*/
