/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:47:50 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:47:53 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

	strjoin cria uma nova string com a junção de s1 e s2.
	
	1. disponibilizar memoria com malloc para s1 + s2 + \0
	2. copiar s1 e depois s2
	3. null terminator e retorno.

*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	n = 0;
	str = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		str[i] = s2[n];
		n++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include<stdio.h>
int main(void)
{
	char    s1[] = "Hello ";
	char    s2[] = "World!";
	char    *str;

	str = ft_strjoin (s1, s2);
	printf ("s1: %s\ns2: %s\nft_strjoin: %s\n", s1, s2, str);
}*/
