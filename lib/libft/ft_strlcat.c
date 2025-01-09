/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:48:03 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:48:06 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

strlcat junta duas strings e garante que o resultado termina em NULL
	pela ordem: dst + src + \0
Se o tam de dstsize NÃO for suficiente para as 2 strings + NULL
	a função faz truncate a string src.

1. usar strlen para saber o tam de dst e src.
2. se o tam de dst for igual a dstsize retorna o tam de dst + src.
	(signif. que não ha espaço em buffer para as duas. sem concatenar)
3. o tamanho de dst nao pode ser maior que dstsize.
4. usar memcpy para adicionar src a dst.
se houver esp para dst + src

*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		dst_len = dstsize;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	if (src_len < dstsize - dst_len)
		ft_memcpy (dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy (dst + dst_len, src, dstsize - dst_len - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
}
/*
#include<stdio.h>
int main(void)
{
	char    s1[] = "Hello ";
	char    s2[] = "World!";
	printf ("s1: %s\ns2: %s\n\n", s1, s2);
	ft_strlcat (s1, s2, 13);
	printf ("Depois de ft_strlcat: %s\n", s1);
}*/