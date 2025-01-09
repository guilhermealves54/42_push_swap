/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:48:11 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:48:13 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

Esta funcao copia uma string e garante que dst termina com NULL.

1. saber o tamanho da src com strlen.
2. se o tamanho de src for maior que dstsize, copia com memcpy
na integra (com pelo menos 1 byte extra para null)
3. se a condição anterior nao se verif faz-se truncate ao 
copiar com dstsize-1 e no fim adiciona o null.
4. se dstsize for 0, nenhuma das condições é verdade e a função
retorna 0 como é suposto.

*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (srcsize + 1 < dstsize)
		ft_memcpy(dst, src, srcsize + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srcsize);
}
/*
#include<stdio.h>
int main(void)
{
	char    src[] = "Hello!";
	char    dst[6];

	printf ("Src original: %s", src);
	ft_strlcpy (dst, src, 6);
	printf ("Dst depois de ft_strlcpy: %s", dst);
}*/
