/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:47:36 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:47:38 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

striteri faz o mesmo que strmapi mas altera a string original
em vez de criar uma nova string.

*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void    test_function(unsigned int i, char *c)
{
	if (i % 2 == 0)
	{
		if (*c >= 'a' && *c <= 'z')
			*c -= 32;
		else if (*c >= 'A' && *c <= 'Z')
			*c += 32;
	}
}

#include<stdio.h>
int main(void)
{
	char    str[] = "Hello World!";

	printf ("Antes: %s\n", str);
	ft_striteri(str, test_function);
	printf ("Depois: %s\n", str);
}*/
