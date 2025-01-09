/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:45:42 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:45:44 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

Semelhante a strchr mas pode trabalhar com qq informação em memoria 
e não so com strings de caracteres.

1. converter ambos os valores em unsigned char para pesquisar byte a byte
2. loop para pesquisar string de bytes. se encontrar retornar esse end.
3. se nao encontrar retornar NULL.

*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	unsigned char	cc;
	size_t			i;

	ss = (unsigned char *) s;
	cc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (ss[i] == cc)
			return ((void *) &ss[i]);
		i++;
	}
	return (NULL);
}
/*
#include<stdio.h>
int main(void)
{
	char arr[] = "abcdefg";
	char c;
	printf ("Valor a encontrar no array:\n");
	scanf ("%c", &c);
	if (ft_memchr(arr, c, 7) != NULL)    
		printf ("\nValor '%c' encontrado.\n", c);
	else
		printf ("\nValor '%c' não encontrado.\n", c);
}*/
