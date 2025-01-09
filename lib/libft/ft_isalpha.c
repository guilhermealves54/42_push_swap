/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:46:01 by gribeiro          #+#    #+#             */
/*   Updated: 2024/10/22 17:08:59 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

Esta função recebe um int e verifica se o valor corresponde a um
caractere alfanumerico.

Em c a conversão de int em char é implicita. 
Usa-se input de int porque possibilita uma maior gama de valores de entrada?

*/

int	ft_isalpha(int n)
{
	if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
	{
		return (1024);
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
	printf ("Resultado ft_isalpha: %d\n", ft_isalpha(c));
	printf ("Resultado isalpha: %d\n", isalpha(c));
}*/
