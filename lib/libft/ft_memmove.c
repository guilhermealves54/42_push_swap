/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:46:21 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:46:23 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

Parecido com memcpy mas impede memory overlapping.

se src estiver num endereço de memor sup ou igual a dst pode usr memcpy

se dst estiver num endereço de memoria sup a src a memoria tera de ser
copiada do ultimo para o primeiro endereço (n decrescente)

*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*tmp_dst;
	char	*tmp_src;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (tmp_dst > tmp_src)
	{
		while (n-- > 0)
		{
			tmp_dst[n] = tmp_src[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	return (dst);
}
/*
#include<stdio.h>
int main(void)
{
	char    src[] = "42Porto";
	char    *dst = src+2;

	printf ("String src: %s\n", src);
	printf ("String dst: %s\n", dst);
	ft_memmove (dst, src, 5);
	printf ("String src: %s\n", src);
	printf ("String dst: %s\n", dst);
}*/
