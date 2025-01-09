/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:45:54 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:45:56 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

igual a strncmp mas com qq tipo de dados e não apenas strings de char.

*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	while (i < n)
	{
		if ((unsigned char) ss1[i] != (unsigned char) ss2[i])
			return ((unsigned char) ss1[i] - (unsigned char) ss2[i]);
		i++;
	}
	return (0);
}
/*
#include<stdio.h>
int main(void)
{
	char    s1[] = "Hello World!";
	char    s2[] = "Hello";
	int n = 0;

	n = ft_memcmp (s1, s2, 13);
	printf ("%d", n);
}*/