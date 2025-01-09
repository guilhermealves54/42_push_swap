/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:44:42 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:44:45 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int n)
{
	if ((n >= '0' && n <= '9') || (n >= 'a' && n <= 'z')
		|| (n >= 'A' && n <= 'Z'))
	{
		return (8);
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
	printf ("Resultado ft_isalnum: %d\n", ft_isalnum(c));
	printf ("Resultado isalnum: %d\n", isalnum(c));
}*/
