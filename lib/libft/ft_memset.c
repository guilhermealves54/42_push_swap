/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:46:34 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:46:35 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

a funcao memset altera blocos de memoria (b) para um det valor c
converte-se int c em unsigned porque alem de permitir alterar byte a byte
(se fosse int alterava logo 4 bytes em sequencia). 
unsigned char permite valores entre 0 e 255.

*/

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp_b;

	temp_b = (unsigned char *) b;
	i = 0;
	while (i < n)
	{
		temp_b[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char    str[] = "Hello!";
	char    c = 'H';
	printf ("String original: %s\n", str);
	ft_memset (str, c, 2);
	printf ("String ft_memset: %s\n", str);
	memset (str, c, 5);
	printf ("String memset: %s\n", str);
}*/