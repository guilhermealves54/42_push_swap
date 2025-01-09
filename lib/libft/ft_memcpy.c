/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:46:04 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:46:07 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

memcpy copia n bytes de memoria de src para dst.
se dst e src forem NULL faz-se retorno de NULL.
caso contrario converte-se em char e copia-se byte a byte ate n

*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	while (n > 0)
	{
		*tmp_dst = *tmp_src;
		tmp_dst++;
		tmp_src++;
		n--;
	}
	return (dst);
}
/*
#include<stdio.h>
int main(void)
{
	char    src[] = "42Porto";
	char    dst[] = "HiWorld";

	printf ("String src: %s\n", src);
	printf ("String dst: %s\n", dst);
	ft_memcpy (dst, src, 7);
	printf ("String src: %s\n", src);
	printf ("String dst: %s\n", dst);
}*/
