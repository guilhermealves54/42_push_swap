/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:45:02 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:45:05 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int n)
{
	if (n >= 0 && n <= 127)
	{
		return (1);
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
	printf ("Resultado ft_isascii: %d\n", ft_isascii(c));
	printf ("Resultado isascii: %d\n", isascii(c));
}*/
